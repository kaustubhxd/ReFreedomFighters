// Node-only helper: load every .ppo under a scripts directory into a ScriptLibrary.
// (The browser builds a ScriptLibrary from fetched bytes with lib.add(relPath, bytes).)
import { readdirSync, readFileSync, statSync } from 'node:fs';
import { join, relative, sep } from 'node:path';
import { ScriptLibrary } from './loader.mjs';

export function listPpo(dir) {
  const out = [];
  const walk = (d) => {
    for (const e of readdirSync(d).sort()) {
      const p = join(d, e);
      const st = statSync(p);
      if (st.isDirectory()) walk(p);
      else if (/\.ppo$/i.test(e)) out.push(p);
    }
  };
  walk(dir);
  return out;
}

/** Accepts either a "scripts" dir or a ZGF extraction root that contains "scripts/". */
export function loadLibrary(dir) {
  let root = dir;
  try { if (statSync(join(dir, 'scripts')).isDirectory()) root = join(dir, 'scripts'); } catch { /* use dir */ }
  const lib = new ScriptLibrary();
  lib.root = root;
  for (const p of listPpo(root)) {
    const rel = relative(root, p).split(sep).join('/');
    try { lib.add(rel, readFileSync(p)); } catch (e) { lib.errors.push({ path: rel, error: e }); }
  }
  return lib;
}
