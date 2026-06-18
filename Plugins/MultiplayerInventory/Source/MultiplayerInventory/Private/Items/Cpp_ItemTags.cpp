#include "Items/Cpp_ItemTags.h"

namespace GameItems {
	namespace Equipment {
		namespace Weapons {
			UE_DEFINE_GAMEPLAY_TAG(Axe, "GameItems.Equipment.Weapons.Axe")
			UE_DEFINE_GAMEPLAY_TAG(Sword, "GameItems.Equipment.Weapons.Sword")
		}
		
		namespace Cloaks {
			UE_DEFINE_GAMEPLAY_TAG(Red, "GameItems.Equipment.Cloaks.Red")
		}
		
		namespace Masks {
			UE_DEFINE_GAMEPLAY_TAG(Steel, "GameItems.Equipment.Masks.Steel")
		}
		
		namespace Consumables {
			namespace Potions {
				namespace Red {
					UE_DEFINE_GAMEPLAY_TAG(Small, "GameItems.Equipment.Consumables.Potions.Red.Small")
					UE_DEFINE_GAMEPLAY_TAG(Large, "GameItems.Equipment.Consumables.Potions.Red.Large")
				}
				namespace Blue {
					UE_DEFINE_GAMEPLAY_TAG(Small, "GameItems.Equipment.Consumables.Potions.Blue.Small")
					UE_DEFINE_GAMEPLAY_TAG(Large, "GameItems.Equipment.Consumables.Potions.Blue.Large")
				}
			}
		}
	}
	
	namespace Craftables {
		UE_DEFINE_GAMEPLAY_TAG(FireFernFruit, "GameItems.Craftables.FireFernFruit")
		UE_DEFINE_GAMEPLAY_TAG(LuminDaisy, "GameItems.Craftables.LuminDaisy")
		UE_DEFINE_GAMEPLAY_TAG(ScorchedPetalBlossom, "GameItems.Craftables.ScorchedPetalBlossom")
	}
}