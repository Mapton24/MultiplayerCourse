// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MultiplayerSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERCOURSE_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
UMultiplayerSessionsSubsystem();

	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

private:

	UFUNCTION()
	void PrintString(const FString& String);

	IOnlineSessionPtr SessionInterface;

	UFUNCTION(BlueprintCallable)
	void CreateServer(const FString& ServerName);
	UFUNCTION(BlueprintCallable)
	void FindServer(const FString& ServerName);

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccesful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	bool bCreateSessionAfterDestroy;
	FString DestroyServerName;
	FString ServerNameToFind;
	FName MySessionName;

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

};
