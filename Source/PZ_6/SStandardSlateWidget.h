// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slate.h"
#include "SlateGameResources.h"
#include "StandardHUD.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class PZ_6_API SStandardSlateWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SStandardSlateWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class AStandardHUD>, OwnerHUD);

	SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);

	TSharedRef<class FSlateGameResources> Create();

protected:	
	TWeakObjectPtr<class AStandardHUD> OwnerHUD;

};
