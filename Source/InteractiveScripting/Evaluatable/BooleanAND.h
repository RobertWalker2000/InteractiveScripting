#pragma once
#include "CoreMinimal.h"
#include "BooleanComparison.h"
#include "BooleanAND.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ABooleanAND : public ABooleanComparison
{
	GENERATED_BODY()
	
public:
	bool Evaluate() override;
};
