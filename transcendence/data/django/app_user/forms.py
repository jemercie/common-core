from django.contrib.auth.forms import UserChangeForm
from django.contrib.auth.models import User
from django import forms
from .models import ProfileModel
from django.contrib.auth.backends import BaseBackend
from django.contrib.auth import get_user_model

class ProfileUpdateForm(UserChangeForm):
    class Meta(UserChangeForm):
        model = ProfileModel
        fields = ['bio']
        exclude = ['user', 'profile_image']

class ProfilePicUpdateForm(UserChangeForm):
    class Meta(UserChangeForm):
        model = ProfileModel
        fields = ['profile_image']
        exclude = ['user', 'bio']

class UsernameUpdateForm(forms.ModelForm):
    class Meta:
        model = User
        fields = ['username']


class PasswordUpdateForm(forms.ModelForm):
    password = forms.CharField(widget=forms.PasswordInput, required=True)
    confirm_password = forms.CharField(widget=forms.PasswordInput, required=True)

    class Meta:
        model = User
        fields = ['password', 'confirm_password']