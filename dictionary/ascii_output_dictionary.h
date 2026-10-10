//---------------------------------------------------------------------------

#pragma once
#include "dictionary.h"

//---------------------------------------------------------------------------

class StenoAsciiOutputDictionary final : public StenoDictionary {
private:
  static constexpr size_t MAXIMUM_OUTLINE_LENGTH = 2;

public:
  StenoAsciiOutputDictionary() : StenoDictionary(MAXIMUM_OUTLINE_LENGTH) {}

  virtual StenoDictionaryLookupResult
  Lookup(const StenoDictionaryLookup &lookup) const;
  using StenoDictionary::Lookup;

  virtual const char *GetName() const;

  static StenoAsciiOutputDictionary instance;
};

//---------------------------------------------------------------------------
