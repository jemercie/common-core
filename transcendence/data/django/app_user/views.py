from django.contrib.auth.forms import AuthenticationForm, UserCreationForm, UserChangeForm, PasswordChangeForm
from django.contrib.auth.decorators import login_required
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout, update_session_auth_hash
from django.http import JsonResponse, HttpResponse
from .models import ProfileModel
from .forms import ProfileUpdateForm, UsernameUpdateForm, PasswordUpdateForm, ProfilePicUpdateForm
from app_index.views import is_connected
from app_chat.models import FriendList, IgnoreList
from app_chat.socket_function import getFriends, isFriend
from project import hook
from django.contrib.auth.models import User
import random
import string
import requests
from django.views.decorators.csrf import csrf_exempt

def getUserProfile( user ):
    try:
        profile = ProfileModel.objects.get(user=user)
        return profile
    except:
        return None

def getUserProfileByLogin42(login):
    try:
        profile = ProfileModel.objects.get(login42=login)
        return profile
    except:
        return None


def getUser( name ):
    try:
        user_query = User.objects.get(username=name)
        return user_query
    except:
        return None

def user_login(request):
    user_status = is_connected(request)
    if user_status:
        context = {
            'is_connected': user_status
        }
        return render(request, "index/home.html", context)
    if request.method == "POST":
        username = request.POST.get("username")
        password = request.POST.get("password")
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            user.profile.is_connected = True
            return JsonResponse({"success": True})
        else:
            return JsonResponse({"success": False, "message": "Identifiant ou mot de passe incorrect"})
    elif request.method == "GET":
        form = AuthenticationForm()
        return render(request, "user/login.html", {"form": form})

@login_required
def user_profile(request, other_user, current):
    if current:
        try:
            profile = request.user.profile
        except ProfileModel.DoesNotExist:
                    profile = ProfileModel.objects.create(user=request.user)
                    profile.save()
                    request.user.save()
        request.user.profile.is_connected = True
    else:
        user = getUser(other_user)
        if user is None:
            return render(request, 'user/error.html')
        else:
            profile = getUserProfile(user)       
    friends_list = getFriends(request.user)
    games_history_data = [
        {"opponent": "cra",  "user_score": 2, "opponent_score": 1, "tournament_final": False},
        {"opponent": "ratatouille", "user_score": 3, "opponent_score": 0, "tournament_final": True},
        {"opponent": "jean-michel", "user_score": 1, "opponent_score": 2, "tournament_final": False},
    ]
    global_dashboard_data = {
        "total_party": 10,
        "total_win": 7,
        "total_loose": 3,
        "dif_win_loose": 4,
        "balls_hit": 200
    }
    games_dashboard_data = [
        {"opponent": "Opponent 1", "user_score": 2, "opponent_score": 1, "in_tournament": False, "tournament_final": False, "balls_hit": 20, "boosts_catch": 5, "max_speed": 100},
        {"opponent": "Opponent 2", "user_score": 3, "opponent_score": 0, "in_tournament": True, "tournament_final": True, "balls_hit": 30, "boosts_catch": 8, "max_speed": 120},
        {"opponent": "Opponent 3", "user_score": 1, "opponent_score": 2, "in_tournament": True, "tournament_final": False, "balls_hit": 25, "boosts_catch": 6, "max_speed": 110},
    ]

    context = {
        'current': current,
        'friends': isFriend(request.user, profile.user),
        'friends_list': friends_list,
        'profile': profile,
        'games_combined': zip(games_history_data, games_dashboard_data),
        'global_dashboard_data':global_dashboard_data,
    }
    return render(request, 'user/profile.html', context)

@login_required
def profile_update(request):

    if request.method == 'POST':
        username_form = UsernameUpdateForm(request.POST, instance=request.user)
        profile_form = ProfileUpdateForm(request.POST, instance=request.user.profile)
        password_form = PasswordChangeForm(user=request.user, data=request.POST)
        profile_picture_form = ProfilePicUpdateForm(request.POST, request.FILES, instance=request.user.profile)
    
        if username_form.is_valid():
            username_form.save()
            return JsonResponse({"success": True})
        elif profile_form.is_valid():
            profile_form.save()
            return JsonResponse({"success": True})
        elif password_form.is_valid():
            update_session_auth_hash(request, request.user)
            password_form.save()
            user = authenticate(request, username=request.user.username, password=password_form.new_password1)
            login(request, user)
            user.profile.is_connected = True
            return JsonResponse({"success": True})
        elif profile_picture_form.is_valid():
            profile_picture_form.save()
            return JsonResponse({"success": True})
        else:
            return JsonResponse({"success": False, "message": "A problem occured while updating your profile."})

    else:
        username_form = UsernameUpdateForm(instance=request.user)
        profile_form = ProfileUpdateForm(instance=request.user.profile)
        password_form = PasswordChangeForm(user=request.user)
        profile_picture_form = ProfilePicUpdateForm(request.FILES, instance=request.user.profile)
        context = {
            'profile_form' : profile_form,
            'username_form' : username_form,
            'password_form' : password_form,
            'profile_picture_form' : profile_picture_form,
        }
        return render(request, 'user/profile_update.html', context)

def user_login(request):
    user_status = is_connected(request)
    if user_status:
        context = {
            'is_connected': user_status
        }
        return render(request, "index/home.html", context)
    if request.method == "POST":
        username = request.POST.get("username")
        password = request.POST.get("password")
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            user.profile.is_connected = True
            return JsonResponse({"success": True})
        else:
            return JsonResponse({"success": False, "message": "Identifiant ou mot de passe incorrect"})
    elif request.method == "GET":
        form = AuthenticationForm()
        return render(request, "user/login.html", {"form": form})

@login_required
def user_logout(request):
    request.user.profile.is_connected = None
    logout(request)
    return JsonResponse({"success": True})

def user_register(request):
    user_status = is_connected(request)
    if user_status:
        context = {
            'is_connected': user_status
        }
        return render(request, "index/home.html", context)
    if request.method == "POST":
        user_form = UserCreationForm(request.POST)
        if user_form.is_valid():
            user_form.save()
            username = user_form.cleaned_data.get('username')
            password = user_form.cleaned_data.get('password1')
            user = authenticate(request, username=username, password=password)
            if user is not None:
                profile = ProfileModel.objects.create(user=user)
                profile.save()
                user.save()
                login(request, user)
                return JsonResponse({"success": True})
        else:
            return JsonResponse({"success": False, "message": "Identifiant ou mot de passe incorrect"})
    else:
        user_form = UserCreationForm()
    return render(request, "user/register.html", {"user_form": user_form})

@csrf_exempt
def register_with_42(request):

    user_status = is_connected(request)
    if user_status:
        context = {
            'is_connected': user_status
        }
        return render(request, "index/home.html", context)
    if request.method == "POST":
        code = request.body.decode('utf-8')
        access_token = obtain_access_token('register', code)
        user_info = get_user_info_from_42(access_token)
        
        if 'error' in user_info:
            return JsonResponse({"success": False, "error": user_info['error']})
        
        username = user_info.get('login')
        profile = getUserProfileByLogin42(username)
        if profile is not None:
            return JsonResponse({"success": False, "message": "You're already registred, sign-in!"})
        login_user = username
        if User.objects.filter(username=username).exists() :
            username = generate_new_username(username)
        new_user = User.objects.create_user(username=username)
        print(username)
        profile = ProfileModel.objects.create(user=new_user)
        profile.login42 = login_user
        profile.profile_image = user_info.get('image_url')
        profile.save()

        try:
            user = User.objects.get(username=username)
            login(request, user)
            if login_user == username:
                return JsonResponse({"success": True, "message": "youpi register and login"})
            else:
                return JsonResponse({"success": True, "message": "You are registred! But your username is already in use, you can choose a new one in the settings!"})
        except User.DoesNotExist:
            return JsonResponse({"success": False, "message": "cant login"})


@csrf_exempt
def login_with_42(request):

    user_status = is_connected(request)
    if user_status:
        context = {
            'is_connected': user_status
        }
        return render(request, "index/home.html", context)
    if request.method == "POST":
        code = request.body.decode('utf-8')
        access_token = obtain_access_token('login', code)
        user_info = get_user_info_from_42(access_token)
        
        if 'error' in user_info:
            return JsonResponse({"success": False, "error": user_info['error']})
        
        username = user_info.get('login')
        profile = getUserProfileByLogin42(username)
        if profile is None:
            return JsonResponse({"success": False, "message": "User doesnt exist, register"})
        try:
            # user = User.objects.get(username=profile.user.username)
            login(request, profile.user)
            return JsonResponse({"success": True, "message": "login"})
        except User.DoesNotExist:
            return JsonResponse({"success": False, "message": "cant login"})

def generate_new_username(username):
    new_username = username + ''.join(random.choices(string.ascii_letters + string.digits, k=4))
    while User.objects.filter(username=new_username).exists():
        new_username += random.choice(string.ascii_letters + string.digits)
    return new_username

def get_user_info_from_42(access_token):
    print("get infos")
    headers = {
        'Authorization': f'Bearer {access_token}'
    }

    response = requests.get('https://api.intra.42.fr/v2/me', headers=headers)

    if response.status_code == 200:
        user_info = response.json()
        return user_info
    else:
        return {'error': 'Failed to fetch user information from 42 API'}

def obtain_access_token(arg, code):
    print("access token")
    url = "https://api.intra.42.fr/oauth/token"

    if arg == 'login':
        print("login payload")
        payload = {
            'grant_type': 'authorization_code',
            'client_id': 'u-s4t2ud-c5b1d7cda698fcaae5901303ddff1e245f32d1df0c0331e045c9452fcdef758c',
            'client_secret': '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',
            'code': code,
            'redirect_uri': 'https://127.0.0.1:8080/login/'
        }
    elif arg == 'register':
        print("register payload")
        payload = {
            'grant_type': 'authorization_code',
            'client_id': 'u-s4t2ud-696cbd27ff289e4159e53fffbec605a118092f89c6b563910981c7b905ddfe67',
            'client_secret': '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',
            'code': code,
            'redirect_uri': 'https://127.0.0.1:8080/register/'
        }

    response = requests.post(url, data=payload)

    if response.status_code == 200:
        print('ugh')
        access_token = response.json()['access_token']
        return access_token
    else:
        print("Error:", response.status_code)
        print(response.json())
        return None
