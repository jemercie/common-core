
from django.conf import settings
from django.views.generic import RedirectView
from django.contrib import admin
from django.urls import include, path
from app_index import views
from django.conf.urls.static import static
from django.urls import re_path

urlpatterns = [
    path('', include("app_index.urls")),
    path('user/', include("app_user.urls")),
    path('chat/', include("app_chat.urls")),
    path('game/', include("app_game.urls")),
    path("admin/", admin.site.urls),
    path('home/', views.index),
    path('game/', views.index),
    path('chat/', views.index),
    path('login/', views.index),
    path('register/', views.index),
    path('profile/', views.index),
    re_path(r'^profile/\w+/$', views.index),
    path('stats/', views.index),
    path('logout/', views.index),
]

if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)