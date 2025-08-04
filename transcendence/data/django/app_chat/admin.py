from django.contrib import admin
from app_chat.models import FriendList, IgnoreList

class FriendListAdmin(admin.ModelAdmin):
    list_display = [field.name for field in FriendList._meta.get_fields()]

admin.site.register(FriendList, FriendListAdmin)

class IgnoreListAdmin(admin.ModelAdmin):
	list_display = [field.name for field in IgnoreList._meta.get_fields()]

admin.site.register(IgnoreList, IgnoreListAdmin)