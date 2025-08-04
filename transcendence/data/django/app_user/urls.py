from django.urls import path
from .views import user_login, user_logout, user_register, user_profile, profile_update, login_with_42, register_with_42

from django.urls import re_path

app_name = "user"

urlpatterns = [
    path('login_with_42/', login_with_42, name = 'login_with_42'),
    path('register_with_42/', register_with_42, name = 'register_with_42'),
    path('login/', user_login, name = 'user_login'),
    path('logout/', user_logout, name = 'user_logout'),
    path('register/', user_register, name = 'user_register'),
    path('profile/', user_profile, {'current': True, 'other_user': 'null'}, name='user_profile'),
    re_path(r'^profile/(?P<other_user>\w+)/$', user_profile, {'current': False}, name='other_user_profile'),
    path('profile_update/', profile_update, name='profile_update'),
]
