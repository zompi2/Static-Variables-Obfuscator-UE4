#pragma once

/**
 * These are traits that defines all of the supported types that can be obfuscated.
 * This obfuscator should work with any kind of static data but just to be safe
 * we define here well tested types. This list can be expanded by the end user.
 */

#include "CoreMinimal.h"

// By default we accept any arithmetic value
template<typename T> struct TVarObSupportedType { enum { Value = TIsArithmetic<T>::Value }; };

// And any other simple structure
template<> struct TVarObSupportedType<FTransform> { enum { Value = true }; };
template<> struct TVarObSupportedType<FVector> { enum { Value = true }; };
template<> struct TVarObSupportedType<FVector2D> { enum { Value = true }; };
template<> struct TVarObSupportedType<FRotator> { enum { Value = true }; };
template<> struct TVarObSupportedType<FQuat> { enum { Value = true }; };
template<> struct TVarObSupportedType<FColor> { enum { Value = true }; };
template<> struct TVarObSupportedType<FLinearColor> { enum { Value = true }; };