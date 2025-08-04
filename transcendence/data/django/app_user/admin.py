from django.contrib import admin
from app_user.models import ProfileModel

class ProfileModelAdmin(admin.ModelAdmin):
    list_display = [field.name for field in ProfileModel._meta.get_fields()]

admin.site.register(ProfileModel, ProfileModelAdmin)