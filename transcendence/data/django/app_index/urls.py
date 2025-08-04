from django.urls import path
from app_index.views import index, home, api_post, api_get, api_delete

urlpatterns = [
    path('', index, name="index-index"),
    path('home_index/', home, name="home-index"),
    path('api_post/', api_post, name="testapi-index"),
    path('api_delete/', api_delete, name="testapi-index"),
    path('api_get/', api_get, name="testapi-index"), 
]
