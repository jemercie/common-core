from django.db import models

class User(models.Model):
    pseudonyme = models.CharField(primary_key = True, max_length = 30)
    connected = models.BooleanField(default = True)

class GamesHistory(models.Model):
    date = models.DateTimeField(auto_now_add = True)
    opponent = models.CharField(max_length = 10)
    user_score = models.IntegerField(default = 0)
    opponent_score = models.IntegerField(default = 0)
    tournament_final = models.BooleanField(default = False)
    user = models.ForeignKey(User, on_delete=models.CASCADE) 

class GamesDashboard(models.Model):
    date = models.DateTimeField(auto_now_add = True)
    opponent = models.CharField(max_length = 10)
    user_score = models.IntegerField(default = 0)
    opponent_score = models.IntegerField(default = 0)
    in_tournament = models.BooleanField(default = False)
    tournament_final = models.BooleanField(default = False)
    balls_hit = models.IntegerField(default = 0)
    boosts_catch = models.IntegerField(default = 0)
    max_speed = models.IntegerField(default = 0)
    user = models.ForeignKey(User, on_delete = models.CASCADE)

class GlobalDashboard(models.Model):
    pseudonyme = models.CharField(primary_key = True, max_length = 30)
    total_party = models.IntegerField(default = 0)
    total_win = models.IntegerField(default = 0)
    total_loose = models.IntegerField(default = 0)
    dif_win_loose = models.IntegerField(default = 0)
    balls_hit = models.IntegerField(default = 0)

class GameCustomization(models.Model):
    pseudonyme = models.CharField(primary_key = True, max_length = 30)
    board = models.CharField(max_length = 50)
    paddles = models.CharField(max_length = 50)
    ball = models.CharField(max_length = 50)
    score = models.CharField(max_length = 50)
    obstacle = models.CharField(max_length = 50)
    number_balls = models.IntegerField(default = 0)