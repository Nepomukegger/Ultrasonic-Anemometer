/*
 * Typst Thesis Expose Template @ Ohm
 *
 * Copyright (c) 2026 Nils Weber <me@vimkat.dev>
 */

#import "styles/ohm.typ" : expose

#show: expose.with(
  type: "bachelor",                     // Type of thesis: master, bachelor, report
  title: [My very fancy thesis title],  // Tyou title
  author: "Georg Simon Ohm",            // Your name
  lang: "en",                           // Language: en, de, de-gender (uses non-binary labels)
  examiners: (                          // People grading your thesis
    [Prof. Dr. Max Mustermann],
    [Prof. Dr. Monika Musterfrau],
  ),
  company: "Example AG",                // Company you're writing you thesis with (delete if not needed)
  supervisors: (                        // People supervising you (at that company or otherwise)
    [Prof. Dr. Max Musterbetreuer],
    [Prof. Dr. Monika Musterbetreuerin],
  ),
  keywords: (                           // Keywords of your thesis for indexing when publishing
    "Container Image",
    "Software Supply Chain Security",
  ),
  bibliography-file: "refs.bib",        // Bibliography file for referencing
  bibliography-style: "ieee",           // Citation style (see Typst docs), 'alphanumeric' supported
)

= Problem description <sec:problem>

First, briefly motivate the topic.
The initial situation should include a short description of the environment or application scenario.
From this, the actual problem statement is derived and the relevance of the solution for practice is outlined.

#lorem(100)

= Thesis Goal <sec:goal>

The thesis goal section outlines the objectives of the planned work and clarifies what the expected result should look like.
It can be helpful to explicitly formulate research questions -- questions that you intend to investigate in your thesis and that can serve as a framework for evaluating different solution approaches.
The goals should briefly describe what is to be produced at the end (a concept, a software system, a process model, a prototype, etc.) and which aspects of the problem are addressed by it.
As with the problem description, this section should be kept concise and to the point.

#lorem(100)

= Approach <sec:approach>

The approach section describes the steps planned to achieve the thesis goal and explains which methods and process models will be applied (mandatory).
It should also address comparable approaches, concepts, or systems that will be examined and evaluated for their transferability to the problem at hand.
The overall structure and progression of the thesis (the common thread) should be recognizable from this description.

#lorem(100)

= Literature <sec:ref>

Please list at least 5 important publications relevant to your thesis.
Sources should meet academic citation standards (i.e., journal articles or textbooks; not Wikipedia, blog posts, or similar).
Reference each work at the appropriate place in the text so that it is clear which part of the thesis each publication supports @Goodliffe2007.

#lorem(100)

= Thesis Outline <sec:outline>

If the problem, goal, approach, and related work sections are already well defined, you can also include a preliminary outline of the thesis structure.

#set enum(full: true)
+ *Introduction*
  + Motivation and problem statement
  + Scope and research questions
  + Contributions and structure of the thesis
+ *Background and Related Work*
  + Example
  + Related work
+ *Implementation*
	+ Example
+ *Evaluation*
+ *Conclusion and Future Work*

#lorem(100)

= Timeline <sec:time>

If you already have a strong idea of the approach, and also some milestones to reach at a certain point, it makes sense to define a schedule so that you can check your progress against it later on. This can be done in a simple tabular format, or using a Gantt chart as shown below.

#import "@preview/timeliney:0.4.0"
#timeliney.timeline(
  show-grid: true,
  {
    import timeliney: *
      
    headerline(group(([*Jul*], 5)), group(([*Aug*], 4)))
    headerline(
      group(..range(1,5, inclusive: true).map(n => strong(str(n)))),
      group(..range(6,9, inclusive: true).map(n => strong(str(n)))),
    )
  
    taskgroup(title: [*Phase 1*], {
      task("Task 1", (1, 3), style: (stroke: 2pt + gray))
      task("Task 2", (4, 6), style: (stroke: 2pt + gray))
    })

    milestone(
      at: 6,
      style: (stroke: (dash: "dashed")),
      align(center, [
        *Milestone*\
        Week 6
      ])
    )
  }
)

#lorem(100)
