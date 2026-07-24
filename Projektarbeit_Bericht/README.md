# Typst Template for Theses and Reports at TH Nürnberg

Basic template for reports, bachelor's theses and master's theses at the [Technische Hochschule Nürnberg Georg Simon Ohm](https://www.th-nuernberg.de/).
This version of the template is intended for digital `PDF/A-2b` compliant submissions.
It is based on the [LaTeX Thesis Template](https://github.com/th-nuernberg/thesis-template) and tries to mirror it as closely as possible.

Feel free to use a local install of [Typst](https://github.com/typst/typst#installation) or the [online editor](https://typst.app).

> [!WARNING]
> The `main` branch is build to be compatible with the new digital Thesis Platform of Computer Science Faculty.
> This Version does not create out of the box a book print format.
> If you need to use the "old" book print format, please open an issue so we can prioritize working on it.
> In the meantime, you can use the [`book-print`](https://github.com/th-nuernberg/thesis-template/tree/book-print) branch of the LaTeX version.

If you are new to Typst, get familiar with its syntax first by reading the [docs](https://typst.app/docs/) and the official [tutorial](https://typst.app/docs/tutorial/).

## Template options

The template function, enabled with `#show: thesis.with(...)` in [`document.typ`](document.typ), provides these options:

| Option               | Type                                  | Description                                                                                                                                                  |
| :------------------- | :------------------------------------ | :----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `type`\*             | `str`                                 | Type of this thesis, can be `bachelor`, `master` or `report`.                                                                                                |
| `title`\*            | `content`                             | Title of the thesis or report.                                                                                                                               |
| `author`\*           | `str`                                 | Author of this thesis or report.                                                                                                                             |
| `student-id`         | `int`                                 | Student ID printed below the author if given.                                                                                                                |
| `date`               | `datetime`                            | Date of this work, defaults to today.                                                                                                                        |
| `bibliography-file`  | `str`                                 | Bibliography to use for this document.                                                                                                                       |
| `bibliography-style` | `str`                                 | Citation standard to use, see https://typst.app/docs/reference/model/bibliography for a full list. `alphanumeric` is supported.                              |
| `lang`               | `str`                                 | Language of this document, only `de` and `en` are fully supported.                                                                                           |
| `book`               | `bool`                                | Whether to layout the document as a book (that can be bound) or not. Not supported yet.                                                                      |
| `header`             | `str, content`                        | Data to include in the header. Can be `none` (empty), `"chapter"` (only current chapter, default), `"full"` (current chapter and section) or custom content. |
| `abstract`\*         | `content, (de: content, en: content)` | Thesis abstract. To use multiple languages, use a dictionary with the language as the key.                                                                   |
| `acknowledgements`   | `content`                             | Additional acknowledgements added to the beginning.                                                                                                          |
| `examiners`          | `str, str[]`                          | Name of the examiner or list of names if multiple examiners.                                                                                                 |
| `supervisors`        | `str, str[]`                          | Name of the supervisor or list of names if multiple supervisors.                                                                                             |
| `keywords`           | `str[]`                               | List of keywords for the title page.                                                                                                                         |
| `company`            | `str`                                 | Company that supported this thesis.                                                                                                                          |
| `glossary`           | `dict`                                | Entries for acronyms and glossary (Hint: Use a separate data file to define them).                                                                           |
| `manual`             | `bool`                                | Don't emit any parts of the document itself, only set the styling options. Structure can be set up manually using the thesis-\* functions.                   |
| `body`               | `content`                             | Thesis content, use as global show rule is encouraged.                                                                                                       |

`*` Required parameter

### Abstract

To define your abstract, you use the `abstract` parameter.
If you write your thesis in German, you can simply provide `content`.

```typst
#show: thesis.with(
	// ...
  abstract: [
    This is my abstract ...
  ],
	// ...
)
```

Alternatively, you can provide a dictionary with `en` and `de` keys, each containing `content`.
The template renders whatever variant corresponds to the main text's language (set using `lang`) first and the alternative version second.
This is _required_ when writing your thesis in English.

```typst
#show: thesis.with(
	// ...
  abstract: (
    en: [
      This is my abstract ...
    ],
    de: [
      Das ist die Kurzdarstellung ...
    ],
  ),
	// ...
)
```

### Glossary

The glossary is powered by the [`glossarium`](https://typst.app/universe/package/glossarium) package.
Refer to its documentation for how to use it.
To define glossary entries, use the `glossary` parameter with a dictionary of the two required keys `acronyms` and `glossary`.

```typst
#show: thesis.with(
	// ...
  glossary: (
    acronyms: (
      // ...
    ),
    glossary: (
      // ...
    ),
  ),
	// ...
)
```

Since defining entries this way is tedious, feel free to use a separate [data file](https://typst.app/docs/reference/data-loading/).
The template logic allows you to use Typst syntax in markup mode inside the data file.
See the [`glossary.yaml`](glossary.yaml) for an example.

### Appendix

If you want to provide additional content aside from your main thesis, you can put it in the appendix.
To start writing, add the show rule `#show: appendix` _after_ your main content and _before_ your appendix content.
This will make sure everything is numbered and placed correctly.

```typst
// ...

= First Chapter

This is my thesis content ...

// ...

#show: appendix

= First Appendix

This is my appendix content ...

// ...
```

### Manual Mode

In case you (or your professor) don't like the structure of this template, you can set the `manual` option to true and lay out the document yourself.
All document parts are available through the `thesis-` functions.
Check out [`styles/ohm.typ`](styles/ohm.typ) to see how they can be used.

| Function                    | Description                                                                                                        |
| :-------------------------- | :----------------------------------------------------------------------------------------------------------------- |
| `thesis-titlepage()`        | Thesis title page showing your thesis title, author and examiner information.                                      |
| `thesis-acknowledgements()` | Acknowledgements in case you want to thank someone.                                                                |
| `thesis-abstract()`         | Thesis abstract in the main language (and optional/required alternate language depending on your language choice). |
| `thesis-toc()`              | Table of contents                                                                                                  |
| `thesis-loa()`              | List of acronyms                                                                                                   |
| `thesis-lof()`              | List of figures                                                                                                    |
| `thesis-lol()`              | List of listings                                                                                                   |
| `thesis-lot()`              | List of tables                                                                                                     |
| `thesis-glossary()`         | Glossary                                                                                                           |
| `thesis-bibliography()`     | Bibliography/References cited in your text.                                                                        |
| `thesis-appendix()`         | Additional resources accompanying your work.                                                                       |

## Compile your document

To build your thesis, you can use the online editor or a local Typst compiler.
Since it's required (and good practice) to submit the PDF in `PDF/A-2b` format, make sure to use the `--pdf-standard a-2b` flag.
To compile your document continuously (whenever something changes), you can use:

```
typst watch --pdf-standard a-2b document.typ
```

## Getting started: writing a thesis expose

A good start for a thesis is to write an expose for the thesis topic.
This repository also provides an expose template written in Typst.

To start an expose, use the show rule `#show: expose.with(...)`.
The options are compatible with the `thesis`-function options.
You can find an example in [`expose.typ`](expose.typ).

## A few tips for writing your thesis

- Create a branch for your thesis; this allows you to easily sync with upstream (this repository).
- Disable automatic hard line wrap (with newlines); use soft wrap instead. [(What's that about?)](https://stackoverflow.com/questions/319925/difference-between-hard-wrap-and-soft-wrap)
- Write one sentence per line -- this makes for nice diffs in git.
- For capitalization of headings, follow the [IEEE Style Manual](https://journals.ieeeauthorcenter.ieee.org/your-role-in-article-production/ieee-editorial-style-manual/).
- Use UTF-8 encoding for your files to make special characters work.
- Keep your literature up to date -- add references to your bib file as you read them.

## Other resources regarding your thesis

- [Informationen Fakultät Informatik](https://elearning.ohmportal.de/mod/page/view.php?id=203579) (German, Ohm intranet)
- [Wie schreibe ich eine Abschlussarbeit](https://www.in.th-nuernberg.de/Professors/Weber/Abschlussarbeit%20Methodik.pdf) by Prof. Dr. Rainer Weber (German, Ohm intranet).
