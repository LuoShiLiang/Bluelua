// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LuaImplementableInterface.h"
#include "LuaImplementableWidget.generated.h"

/**
 *
 */
UCLASS()
class BLUELUA_API ULuaImplementableWidget : public UUserWidget, public ILuaImplementableInterface
{
	GENERATED_BODY()

protected:
	virtual void ProcessEvent(UFunction* Function, void* Parameters) override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void BeginDestroy() override;
	virtual FString OnInitBindingLuaPath_Implementation() override;
	virtual bool ShouldEnableLuaBinding_Implementation() override;

	void TickActions(float InDeltaTime);

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "LuaImplementable", meta = (AllowPrivateAccess = "true"))
	FString LuaFilePath;
};
