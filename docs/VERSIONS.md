# VERSIONS — muse ↔ bundle ↔ schema pins

| bundle | muse-code | schema fingerprint (stable) | status |
|---|---|---|---|
| 0.1.0 | 1.3.0-R3057.1 | `sha256:ab69549a7ebb423fce94068762da0b5ff3cdec1f8fc263dcc17248eda117f852` | current |

Pinned exports live in `schema/stable-<muse-version>/`
(`msp.schema.json` + `manifest.json`).

Rule: a new Muse Code release re-runs `tools/muse-*` in order. If the
stable fingerprint is unchanged AND the vocabulary harvest is clean,
the pin stays green with a new row. Any fingerprint or vocabulary
delta opens a bundle patch before the row is added.
