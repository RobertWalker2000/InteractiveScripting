// Fill out your copyright notice in the Description page of Project Settings.
#include "IfStatement.h"

UIfStatement::UIfStatement()
{

}

UExecutable::ExecuteResult UIfStatement::Execute()
{
	UExecutable::ExecuteResult insideResult = EndReached;

	//Check the condition and execute the conditional code only if it returns true
	if (condition->Evaluate() == true && insideLine != NULL)
	{
		insideResult = insideLine->Execute();
	}

	//Check the result from the conditional code. If it is EndReached then either condition was false or conditional code executed succesfully
	if (insideResult == EndReached)
	{
		if (nextLine == NULL)
			return EndReached;
		else
			return nextLine->Execute();
	}
	else //If result is anything else, something went wrong while running the conditional code and we can't continue
	{
		return insideResult;
	}

}