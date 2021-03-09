#pragma once
#include "CoreMinimal.h"
#include "BooleanComparison.h"
#include "BooleanOR.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ABooleanOR : public ABooleanComparison
{
	GENERATED_BODY()
	
public:
	bool Evaluate() override;
};
