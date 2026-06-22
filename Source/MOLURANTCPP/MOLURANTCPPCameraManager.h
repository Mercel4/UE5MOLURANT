#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "MOLURANTCPPCameraManager.generated.h"

/**
 *  Basic First Person camera manager.
 *  Limits min/max look pitch.
 */
UCLASS()
class AMOLURANTCPPCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	AMOLURANTCPPCameraManager();
};
