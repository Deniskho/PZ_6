// Fill out your copyright notice in the Description page of Project Settings.

#include "StandardHUD.h"
#include "SStandardSlateWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

void AStandardHUD::BeginPlay()
{
	MyUIWidget = SNew(SStandardSlateWidget).OwnerHUD(this);

	GEngine->GameViewport->AddViewportWidgetContent(
		SNew(SWeakWidget)
		.PossiblyNullContent(MyUIWidget.ToSharedRef())
	);

	MyUIWidget->SetVisibility(EVisibility::Visible);
}
