#include "g_class.h"

void CheckClass(edict_t* ent){
	if (ent->client->resp.class < 1)   //Do we already have an Class?
	{       //Nope? Then send message...
		gi.centerprintf(ent, "Choose your class:\n\nG - Soldier\n\nM - Pyro\n\nO - Heavy\n\nR - Scout\n\n\n\n F - Sniper");
	}
}

void StartPerk(edict_t* ent, int perk) {
	ent->client->perkInitiated = true;
	ent->client->perk_time = 15;
	ent->client->perkType = perk;
	switch (perk) {
	case 0:
		//gi.centerprintf(ent, "Crit Bullets!!");
		break;
	case 1:
		//gi.centerprintf(ent, "Speed Boost!!");
		break;
	case 2:
		//gi.centerprintf(ent, "Double Health!!");
		break;
	case 3:
		//gi.centerprintf(ent, "Explosive Weapons!!");
		break;
	case 4:
		//gi.centerprintf(ent, "Speed Decreased...");
		break;
	};
}
void Cmd_Class_f(edict_t* ent, char* cmd) 
{
	if (Q_stricmp(cmd, "soldier") == 0) {
		ent->client->resp.class = 1;
		gi.centerprintf(ent, "You have chosen Soldier!\n\n\n");
		
		Cmd_Kill_f(ent);
	}
	else if (Q_stricmp(cmd, "pyro") == 0) {
		ent->client->resp.class = 2;
		gi.centerprintf(ent, "You have chosen Pyro!\n\n\n");
		Cmd_Kill_f(ent);
	}
	else if (Q_stricmp(cmd, "heavy") == 0) {
		ent->client->resp.class = 3;
		gi.centerprintf(ent, "You have chosen Heavy!\n\n\n");
		Cmd_Kill_f(ent);
	}
	else if (Q_stricmp(cmd, "scout") == 0) {
		ent->client->resp.class = 4;
		gi.centerprintf(ent, "You have chosen Scout!\n\n\n");
		

		Cmd_Kill_f(ent);
	}
	else if (Q_stricmp(cmd, "sniper") == 0) {
		ent->client->resp.class = 5;
		gi.centerprintf(ent, "You have chosen Sniper!\n\n\n");
		Cmd_Kill_f(ent);
	}
	else {
		ent->client->resp.class = 0;
		gi.centerprintf(ent, "Invalid selection!\n");
	}

	chosenClass = ent->client->resp.class;
}

void Cmd_SwitchClass_f(edict_t* ent, char* cmd)
{
	gi.centerprintf(ent, "Choose your class:\n\nG - Soldier\nM - Pyro\n");
	if (Q_stricmp(cmd, "soldier") == 0) {
		ent->client->resp.class = 1;
		gi.centerprintf(ent, "You have chosen Soldier.\n\n\n");
		Cmd_Kill_f(ent);
	}
	else if (Q_stricmp(cmd, "pyro") == 0) {
		ent->client->resp.class = 2;
		gi.centerprintf(ent, "You have chosen Pyro.\n\n\n");
		Cmd_Kill_f(ent);
	}
	else {
		ent->client->resp.class = 0;
		gi.centerprintf(ent, "Invalid selection!\n");
	}
}