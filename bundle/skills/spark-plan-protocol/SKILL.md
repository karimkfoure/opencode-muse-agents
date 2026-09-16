---
name: spark-plan-protocol
description: Implementation planning for Spark workers with acceptance criteria and evidence paths
---

## What I do

Turn a goal into worker-sized units, each with exactly one question,
fixed inputs, an owned worktree, a budget, and the expected evidence.

## When to use me

Use when the coordinator must fan out parallel work. Every unit needs:
question, inputs, worktree, budget (steps or time), expected evidence
files, and the acceptance check the reviewer will run.

## Rules

- One question per unit. Two questions means two units.
- Evidence paths, not prose, prove completion.
- Record the plan (units + owners + budgets) before spawning anything.
- Variants go through fork records with opaque provenance, never by
  copying chat text.
