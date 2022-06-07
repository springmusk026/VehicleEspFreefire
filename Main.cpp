#include "EntityList.h"

/////HOOK CLASS VEHICLE
void (*orig_VehicleUpdate)(void *componentv);
void _VehicleUpdate(void *v) {
  if(v != NULL){
     vehicleManager->tryAddEnemy(player);
     vehicleManager->updateEnemies(player);
  }
  ///direct implementation  may cause crash so use it by making proper conditions
 
  
  orig_VehicleUpdate(player);
}


/////put this inside your esp class

 if (vehicleManager->enemies->empty()) {
                return;
            }
            for (int i = 0; i < vehicleManager->enemies->size(); i++) {
                void *Vehicle = (*vehicleManager->enemies)[i]->object;
                
                Vector3 VehiclePos =Transform_INTERNAL_GetPosition(get_Transform(Vehicle));
                void *Cam = Camera_main();
                Vector3 PosNew = WorldToScreenPoint(Cam, VehiclePos);
                if (PosNew.Z < 1.f) continue;
                float distance = Vector3::Distance(GetAttackableCenterWS(Current_Local_Player()), VehiclePos);

                if(distance< configs.esp.vMinDist){
                    if(configs.esp.vLine){
                        esp.DrawLine(Color::White(), 0.5f, Vector3((screenWidth / 2), screenHeight/20),  Vector3((screenWidth - (screenWidth - PosNew.X)), (screenHeight -PosNew.Y)));
                    }
                    if(configs.esp.vDist){
                        char buffer[30];
                        sprintf(buffer, "Vehicle : [ %.2fm ]", distance);
                        esp.DrawText(Color::White(), buffer, Vector3((screenWidth - (screenWidth - PosNew.X)), (screenHeight -PosNew.Y)), 10.0f);
                    }
                }
            }
            
            
            
/////Put this on your hack thread

 vehicleManager = new VehicleManager();
HOOK(string2Offset(OBFUSCATE_KEY("0x10100C8", 'k')), _VehicleUpdate, orig_VehicleUpdate);
            
