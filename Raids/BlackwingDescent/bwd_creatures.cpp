#include "ScriptPCH.h"


enum eSpells
{
	// Spells Drakonid ChaineWilder
	SPELL_BLESSURE_GRAVE			= 80051,
	SPELL_FRAPPE					= 79580,

	// Spells Drakonid Drudge
	SPELL_CHARGE					= 79630,
	SPELL_COUP_TONNERRE				= 79604,

	//Spells Golem Sentry
	SPELL_BOMBE_ECLERANTE			= 81056,
	SPELL_DECHARGE_ELECTRIQUE		= 81055,
	SPELL_FRAPPE_LASER				= 81063,

	// Spells Ivoroc
	SPELL_MALEDICTION_DE_GERISON	= 80295,
	SPELL_OMBRE_FLAMME				= 80270,

	// Spells Maimgor
	SPELL_ENRAGE					= 80084,
	SPELL_FOUETTE_QUEUE				= 80130,
	SPELL_ETREINTE = 80145,

};

class bwd_creature_drakonid_chainewilder : public CreatureScript // Drakonid ChaineWilder
{
public:
    bwd_creature_drakonid_chainewilder() : CreatureScript("bwd_creature_drakonid_chainewilder") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bwd_creature_drakonid_chainewilderAI (creature);
    }

    struct bwd_creature_drakonid_chainewilderAI : public ScriptedAI
    {
        bwd_creature_drakonid_chainewilderAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

		uint32 uiFrappeTimer;
		uint32 uiBlessureGraveTimer;
        uint32 uiTimer;

        void Reset()
        {
			uiFrappeTimer = 10000;
			uiBlessureGraveTimer = 5000;
            uiTimer = 0;
        }

		void UpdateAI(const uint32 uiDiff)
    	{
    		if (!me->getVictim())
           	{
    		}
    		
    		if (!UpdateVictim())
    			return;

				if (uiBlessureGraveTimer <= uiDiff)
				{
						DoCast(me->getVictim(), SPELL_BLESSURE_GRAVE);
						uiBlessureGraveTimer = 50000;
				}
				else
					uiBlessureGraveTimer -= uiDiff;

				if (uiFrappeTimer <= uiDiff)
				{
						DoCast(me->getVictim(), SPELL_FRAPPE);
						uiFrappeTimer = 10000;
				}
				else
					uiFrappeTimer -= uiDiff;

    	DoMeleeAttackIfReady();
    	}
    };

};

class bwd_creature_drakonid_drudge : public CreatureScript // Drakonid ChaineWilder
{
public:
    bwd_creature_drakonid_drudge() : CreatureScript("bwd_creature_drakonid_drudge") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bwd_creature_drakonid_drudgeAI (creature);
    }

    struct bwd_creature_drakonid_drudgeAI : public ScriptedAI
    {
        bwd_creature_drakonid_drudgeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

		uint32 uiChargeTimer;
		uint32 uiCoupTonnerreTimer;
        uint32 uiTimer;

        void Reset()
        {
			uiChargeTimer = 15000;
			uiCoupTonnerreTimer = 10000;
            uiTimer = 0;
        }

		void UpdateAI(const uint32 uiDiff)
    	{
    		if (!me->getVictim())
           	{
    		}
    		
    		if (!UpdateVictim())
    			return;

				if (uiCoupTonnerreTimer <= uiDiff)
				{
						DoCast(me->getVictim(), SPELL_COUP_TONNERRE);
						uiCoupTonnerreTimer = 10000;
				}
				else
					uiCoupTonnerreTimer -= uiDiff;

				if (uiChargeTimer <= uiDiff)
				{
						DoCast(me->getVictim(), SPELL_CHARGE);
						uiChargeTimer = 15000;
				}
				else
					uiChargeTimer -= uiDiff;

    	DoMeleeAttackIfReady();
    	}
    };

};

class bwd_creature_golem_sentry : public CreatureScript // Golem Sentry
{
public:
    bwd_creature_golem_sentry() : CreatureScript("bwd_creature_golem_sentry") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bwd_creature_golem_sentryAI (creature);
    }

    struct bwd_creature_golem_sentryAI : public ScriptedAI
    {
        bwd_creature_golem_sentryAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

		uint32 uiBombeEcleranteTimer;
		uint32 uiDechargeElectriqueTimer;
		uint32 uiFrappeLaserTimer;
        uint32 uiTimer;

        void Reset()
        {
			uiBombeEcleranteTimer = 12500;
			uiDechargeElectriqueTimer = 10000;
			uiFrappeLaserTimer = 15000;
            uiTimer = 0;
        }

		void UpdateAI(const uint32 uiDiff)
    	{
    		if (!me->getVictim())
           	{
    		}
    		
    		if (!UpdateVictim())
    			return;

				if (uiDechargeElectriqueTimer <= uiDiff)
				{
						DoCast(me->getVictim(), SPELL_DECHARGE_ELECTRIQUE);
						uiDechargeElectriqueTimer = 10000;
				}
				else
					uiDechargeElectriqueTimer -= uiDiff;

				if (uiFrappeLaserTimer <= uiDiff)
				{
					if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
					
						DoCast(target, SPELL_FRAPPE_LASER);
						uiFrappeLaserTimer = 15000;				
				}
				else
					uiFrappeLaserTimer -= uiDiff;

				if (uiBombeEcleranteTimer <= uiDiff)
				{
					if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
					
						DoCast(target, SPELL_BOMBE_ECLERANTE);
						uiBombeEcleranteTimer = 12500;				
				}
				else
					uiBombeEcleranteTimer -= uiDiff;

    	DoMeleeAttackIfReady();
    	}
    };

};


class bwd_creature_ivoroc : public CreatureScript // Ivoroc
{
public:
    bwd_creature_ivoroc() : CreatureScript("bwd_creature_ivoroc") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bwd_creature_ivorocAI (creature);
    }

    struct bwd_creature_ivorocAI : public ScriptedAI
    {
        bwd_creature_ivorocAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

		uint32 uiMaledictionDeGerisonTimer;
		uint32 uiOmbreFlammeTimer;
        uint32 uiTimer;

        void Reset()
        {
			uiMaledictionDeGerisonTimer = 10000;
			uiOmbreFlammeTimer = 15000;
            uiTimer = 0;
        }

		void UpdateAI(const uint32 uiDiff)
    	{
    		if (!me->getVictim())
           	{
    		}
    		
    		if (!UpdateVictim())
    			return;

			if (uiOmbreFlammeTimer <= uiDiff)
			{
				DoCast(me->getVictim(), SPELL_OMBRE_FLAMME);
				uiOmbreFlammeTimer = 10000;
			}
			else
				uiOmbreFlammeTimer -= uiDiff;

			if (uiMaledictionDeGerisonTimer <= uiDiff)
			{
				if (Unit *Target = SelectTarget(SELECT_TARGET_RANDOM, 0))

					DoCast(Target, SPELL_MALEDICTION_DE_GERISON);
					uiMaledictionDeGerisonTimer = 15000;
			}
			else
				uiMaledictionDeGerisonTimer -= uiDiff;


    	DoMeleeAttackIfReady();
    	}
    };

};

// Npc Maimgor
class bwd_creature_maimgor : public CreatureScript // Maimgor
{
public:
    bwd_creature_maimgor() : CreatureScript("bwd_creature_maimgor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bwd_creature_maimgorAI (creature);
    }

    struct bwd_creature_maimgorAI : public ScriptedAI
    {
        bwd_creature_maimgorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

		uint32 uiEnrageTimer;
		uint32 uiFouetteQueueTimer;
		uint32 uiOmbreFlammeTimer;
		uint32 uiEtreinteTimer;
        uint32 uiTimer;

        void Reset()
        {
			uiEnrageTimer = 7000;
			uiFouetteQueueTimer = 12000;
			uiOmbreFlammeTimer = 10000;
            uiTimer = 0;
        }

		void UpdateAI(const uint32 uiDiff)
    	{
    		if (!me->getVictim())
           	{
    		}
    		
    		if (!UpdateVictim())
    			return;

			if (uiEnrageTimer <= uiDiff)
			{
				DoCast(me->getVictim(), SPELL_ENRAGE);
				uiEnrageTimer = 7000;
			}
			else
				uiEnrageTimer -= uiDiff;

			if (uiFouetteQueueTimer <= uiDiff)
			{
				DoCastAOE(SPELL_FOUETTE_QUEUE);
				uiFouetteQueueTimer = 12000;
			}
			else
				uiFouetteQueueTimer -= uiDiff;

			if (uiOmbreFlammeTimer <= uiDiff)
			{
				if (Unit *Target = SelectTarget(SELECT_TARGET_RANDOM, 0))

					DoCast(Target, SPELL_OMBRE_FLAMME);
					uiOmbreFlammeTimer = 10000;
			}
			else
				uiOmbreFlammeTimer -= uiDiff;

			if (uiEtreinteTimer <= uiDiff)
			{
				if (Unit *Target = SelectTarget(SELECT_TARGET_RANDOM, 0))

					DoCast(Target, SPELL_ETREINTE);
					uiEtreinteTimer = 15000;
			}
			else
				uiEtreinteTimer -= uiDiff;


    	DoMeleeAttackIfReady();
    	}
    };

};

void AddSC_bwd_creature_drakonid_chainewilder()
{
	new bwd_creature_drakonid_chainewilder();
	new bwd_creature_drakonid_drudge();
	new bwd_creature_golem_sentry();
	new bwd_creature_ivoroc();
	new bwd_creature_maimgor();
}
