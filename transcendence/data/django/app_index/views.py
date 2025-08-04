from django.shortcuts import render
from django.http import HttpResponse
import requests

def is_connected(request):
    try:
        profile = request.user.profile
        is_connected = profile.is_connected
    except:
        is_connected = None
    return (is_connected)


def home(request):
    is_user_connected = is_connected(request)
    context = {
        'is_connected': is_user_connected
    }
    return render(request, "index/home.html", context)

def index(request):
    is_user_connected = is_connected(request)
    context = {
        'is_connected': is_user_connected
    }
    return render(request, "index/index.html", context)



def api_post(request):
	url = 'http://ms-user:8002/api/user/'

	data = {}
	data['login'] = 'TestInsert'
	data['email'] = 'test@gmail.com'
	data['password'] = 'pass'
	data['pseudonyme'] = 'Salut'
	data['active'] = True

	url_get = url + data['login']
	response = requests.get( url_get )
	if response.status_code == 200:
		return HttpResponse( "L'utilisateur existe deja" )

	response = requests.post(url, json=data)
	if response.status_code == 201:
		return HttpResponse( "L'utilisateur a ete cree avec succes")
	
	return HttpResponse( "Une erreur est rencontre")

def api_delete(request):
	url = 'http://ms-user:8002/api/user/'
	url = url + 'TestInsert'
	response = requests.delete( url )

	return HttpResponse(response.status_code)

def api_get(request):
	url = 'http://ms-user:8002/api/user/'
	url = url + 'mbouin'
	# url = url + '?login=mbouin'
	# url = url + '/?format=json'
	response = requests.get( url )
	response = response.json()

	# for i in response.json():
	return HttpResponse( response['login'] )
	