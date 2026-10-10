//---------------------------------------------------------------------------

#include "ascii_output_dictionary.h"

//---------------------------------------------------------------------------

StenoAsciiOutputDictionary StenoAsciiOutputDictionary::instance;

//---------------------------------------------------------------------------

StenoDictionaryLookupResult
StenoAsciiOutputDictionary::Lookup(const StenoDictionaryLookup &lookup) const {
  if (lookup.length != 2) {
    return StenoDictionaryLookupResult::CreateInvalid();
  }

  StenoStroke enable[2];
  enable[0].Set("SAOEUTSDZ");
  enable[1].Set("PWOBG");
  if (StenoStroke::Equals(lookup.strokes, enable, 2)) {
    return StenoDictionaryLookupResult::CreateStaticString(
        "{:set_ascii_output:on}");
  }

  StenoStroke disable[2];
  disable[0].Set("SAO*EUTSDZ");
  disable[1].Set("PWOBG");
  if (StenoStroke::Equals(lookup.strokes, disable, 2)) {
    return StenoDictionaryLookupResult::CreateStaticString(
        "{:set_ascii_output:off}");
  }

  return StenoDictionaryLookupResult::CreateInvalid();
}

const char *StenoAsciiOutputDictionary::GetName() const {
  return "#internal#ascii_output_dictionary";
}

//---------------------------------------------------------------------------
