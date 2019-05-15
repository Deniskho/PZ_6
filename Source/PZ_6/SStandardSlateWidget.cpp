// Fill out your copyright notice in the Description page of Project Settings.

#include "SStandardSlateWidget.h"
#include "SlateOptMacros.h"
#include "PZ_6.h"
#include "Modules/ModuleManager.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
#define LOCTEXT_NAMESPACE "SStandardSlateWidget"

void SStandardSlateWidget::Construct(const FArguments& InArgs) 
{

	OwnerHUD = InArgs._OwnerHUD;
	FString ImagePath = FPaths::GameContentDir() + TEXT("default_pictures/test.png");
	FName BrushName = FName(*ImagePath);

	ChildSlot
    .VAlign(VAlign_Fill)
	.HAlign(HAlign_Fill)
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Center)
		[
			SNew(STextBlock)
			.ShadowColorAndOpacity(FLinearColor::Black)
		    .ColorAndOpacity(FLinearColor::Red)
		    .ShadowOffset(FIntPoint(-1,1))
		    .Font(FSlateFontInfo("Veranda",16))
		.Text(LOCTEXT("HelloSLateText","Hello,Slate!"))
		]
	+ SOverlay::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		[
			SNew(SImage)
			.Image(new FSlateImageBrush(BrushName, FVector2D(128, 128)))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Bottom)
		[/* [ operator begins adding things to our new slot's contents */
			SNew(SHorizontalBox).Visibility(EVisibility::Visible)
			//Add slots to HorizontalBox, these will hold images
		+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[   //
			SNew(SImage).Image(new FSlateImageBrush(BrushName, FVector2D(100, 100)))
		]
	+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[
			SNew(SImage).Image(new FSlateImageBrush(BrushName, FVector2D(100, 100)))
		]
	+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[
			SNew(SImage).Image(new FSlateImageBrush(BrushName, FVector2D(100, 100)))
		]
	+ SHorizontalBox::Slot().HAlign(HAlign_Left).VAlign(VAlign_Bottom)
		[
			SNew(SImage).Image(new FSlateImageBrush(BrushName, FVector2D(100, 100)))
		]

		]

	];



}

#undef LOCTEXT_NAMESPACE

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


