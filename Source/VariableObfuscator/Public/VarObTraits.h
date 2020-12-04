#pragma once

#include "CoreMinimal.h"
#include "HAL/Platform.h"

// By default we accept any arithmetic value
template<typename T> struct TVarObSupportedType { enum { Value = TIsArithmetic<T>::Value }; };

// And any other simple structure
template<> struct TVarObSupportedType<FVector> { enum { Value = true }; };
template<> struct TVarObSupportedType<FVector2D> { enum { Value = true }; };
template<> struct TVarObSupportedType<FRotator> { enum { Value = true }; };
template<> struct TVarObSupportedType<FQuat> { enum { Value = true }; };
template<> struct TVarObSupportedType<FColor> { enum { Value = true }; };
