from django.core.management.base import BaseCommand
from django.contrib.auth import get_user_model
import os

UserModel = get_user_model()

ADMIN_ID = 'admin'
ADMIN_PASSWORD = 'admin'

class Command(BaseCommand):
	help = 'Initialize project for local development'
		
	def handle(self, *args, **options):
		if os.path.isfile( "./init_users.txt" ):
			self.stdout.write(self.style.SUCCESS("Block import"))
			return
		f = open("init_users.txt", "w")
		f.write("True")
		f.close()

		self.stdout.write(self.style.MIGRATE_HEADING(self.help))
		UserModel.objects.create_superuser(ADMIN_ID, 'admin@42.com', ADMIN_PASSWORD)
		self.stdout.write(self.style.SUCCESS("All Done !"))
		
