
from django.db import models
from django.contrib.auth.models import User


class ProfileModel(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, related_name='profile')
    login42 = models.CharField(max_length=8)
    bio = models.CharField(max_length=255)
    profile_image = models.ImageField(default="images/profile-pic/default_profile_pic.png", upload_to='images/profile-pic/', null=True, blank=True)
    is_connected = True
    def __str__(self):
        return self.user.username

