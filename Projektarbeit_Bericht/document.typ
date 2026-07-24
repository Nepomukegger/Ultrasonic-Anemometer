/*
 * Typst Thesis Template @ Ohm
 *
 * Copyright (c) 2026 Nils Weber <me@vimkat.dev>
 */

#import "styles/ohm.typ" : thesis, appendix

#show: thesis.with(
  type: "report",                     // Type of thesis: master, bachelor, report
  title: [Ultrasonic Anemometer for Wind Speed Measurement],  // Your title
  author: ("Christopher Höck",            // Your name
    "Nepomuk Egger",
  ),
  student-id: 3536119,                  // Your student id
  lang: "en",                           // Language: en, de, de-gender (uses non-binary labels)
  examiners: (                          // People grading your thesis
    [Prof. Dr. Bernd Klehn],
  ),
  keywords: (                           // Keywords of your thesis for indexing when publishing
    "Container Image",
    "Software Supply Chain Security",
  ),
  acknowledgements: [                   // Optional
    Only if you want to thank someone.
  ],
  abstract: (                           // Abstract in German and/or English based on regulations
    en: [
      Only if thesis is written in English.
    ],
    de: [
      Kurze Zusammenfassung der Arbeit, höchstens eine halbe Seite.
      Deutsche Fassung auch nötig, wenn die Arbeit auf Englisch angefertigt wird.
      Das Template warnt vor falschen Angaben.
    ]
  ),
  glossary: yaml("glossary.yaml"),      // Glossary entries and acronyms (from external file)
  bibliography-file: "refs.bib",    // Bibliography file for referencing
  bibliography-style: "ieee",           // Citation style (see Typst docs), 'alphanumeric' supported
  header: "full",
)

#include "content/01-intro.typ"         // Main content of this thesis. You can put your
#include "content/02-data.typ"          // content into this file directly or split it
#include "content/03-method.typ"        // over multiple files to keep it organized.
#include "content/04-experiments.typ"   //
#include "content/05-outlook.typ"       //
#include "content/06-summary.typ"       //

#show: appendix                         // Switch from main content to appendix

#include "content/A1-supplemental.typ"  // Same as with main content
