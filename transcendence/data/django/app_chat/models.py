from django.db import models
from django.contrib.auth.models import User

class FriendList( models.Model ):
	fromUser = models.ForeignKey(User, related_name="fromUserFriend", on_delete=models.CASCADE)
	toUser = models.ForeignKey(User, related_name="toUserFriend", on_delete=models.CASCADE)

class IgnoreList( models.Model ):
	fromUser = models.ForeignKey(User, related_name="fromUserIgnore", on_delete=models.CASCADE)
	toUser = models.ForeignKey(User, related_name="toUserIgnore", on_delete=models.CASCADE)