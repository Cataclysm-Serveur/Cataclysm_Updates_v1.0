#include "ScriptPCH.h"


enum eSpells
{

};

class bot_creature_ : public CreatureScript // 
{
public:
    bot_creature_() : CreatureScript("bot_creature_") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bot_creature_AI (creature);
    }

    struct bot_creature_AI : public ScriptedAI
    {
        bot_creature_AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiTimer;

        void Reset()
        {
            uiTimer = 0;
        }

		void UpdateAI(const uint32 uiDiff)
    	{
    		if (!me->getVictim())
           	{
    		}
    		
    		if (!UpdateVictim())
    			return;


    	DoMeleeAttackIfReady();
    	}
    };

};

void AddSC_bot_creatures()
{
}
