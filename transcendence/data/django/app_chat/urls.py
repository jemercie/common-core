from django.urls import path
from app_chat.views import index

app_name = "chat"

urlpatterns = [
    path('index/', index, name="index"),
]