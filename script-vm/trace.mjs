#!/usr/bin/env node
// Run one compiled script in the VM and print its state changes, events, messages and native calls.
//
// usage: node script-vm/trace.mjs <scripts_dir> <script.ppo> [options]
//   --act N[,N...]   send "StartAct N" (comma list = sequence, one act after each CompletedAct)
//   --at SEC         game time of the first StartAct (default 1)
//   --ticks N        scheduler frames to run (default 600 = 20 s at 30 fps)
//   --dt SEC         frame length (default 1/30)
//   --no-sim         no simulated movement/sound natives (bindActorSimulation)
//   --all-natives    also print quiet natives (stackIdx, =CStr, ...) and getAnimHandle
//   --ops            print every instruction
//   --var NAME=VAL   set an exported variable (repeatable); by default every exported
//                    ZGEOMREF gets a distinct fake scene ref 1000+i so traces stay readable
// Exported for tests: runTrace(options) -> { world, proc, lines, sends, states, natives }.
import { loadLibrary } from './fsload.mjs';
import { World } from './vm.mjs';
import { NativeRegistry, bindActorSimulation } from './natives.mjs';

export function runTrace({
  scriptsDir, script, acts = [], at = 1, ticks = 600, dt = 1 / 30, sim = true,
  allNatives = false, ops = false, vars = {}, print = null, registry = null, actGap = 1,
} = {}) {
  const lib = loadLibrary(scriptsDir);
  const prog = lib.program(script);
  const lines = [];
  const out = (s) => { lines.push(s); print?.(s); };
  const reg = registry ?? new NativeRegistry({ log: (s) => out(`        ${s}`) });
  if (sim && !registry) bindActorSimulation(reg);
  const states = []; const sends = []; const natives = [];
  const hide = allNatives ? null : /^getAnimHandle$/i;
  const fmtT = (t) => `t=${t.toFixed(2).padStart(6)}`;
  const world = new World({
    natives: reg,
    log: (s) => out(`        ${s}`),
    trace: (e) => {
      const who = `[${e.proc ?? '-'}]`;
      switch (e.kind) {
        case 'state': states.push(e); out(`${fmtT(e.t)} ${who} STATE ${e.from ?? '(none)'} -> ${e.to}`); break;
        case 'ctor-end': out(`${fmtT(e.t)} ${who} constructor done, start state ${e.start}`); break;
        case 'event': out(`${fmtT(e.t)} ${who} EVENT ${e.name}(${e.args.join(', ')})${e.from ? ' from ' + e.from : ''}`); break;
        case 'send': sends.push(e); out(`${fmtT(e.t)} ${who} SEND ${e.name}(${e.args.join(', ')}) -> ${e.to}`); break;
        case 'native':
          natives.push(e);
          if (!hide || !hide.test(e.method)) out(`${fmtT(e.t)} ${who}   ${e.cls}.${e.method}(${e.args.join(', ')})${e.rets.length ? ' -> ' + e.rets.join(', ') : ''}${e.implemented ? '' : '  [stub]'}`);
          break;
        case 'op': out(`${fmtT(e.t)} ${who}     ${e.ip.toString(16).padStart(5, '0')} ${e.text}`); break;
        case 'error': out(`${fmtT(e.t)} ${who} ERROR ${e.message}`); break;
        case 'terminate': out(`${fmtT(e.t)} ${who} TERMINATE`); break;
        default: break;
      }
    },
  });
  world.traceOps = ops;
  // fake scene refs for exported variables
  const autoVars = {};
  prog.vars.forEach((v, i) => { if (!v.listType && /ZGEOMREF/i.test(v.type)) autoVars[v.name] = 1000 + i; });
  Object.assign(autoVars, vars);
  const legend = Object.entries(autoVars).map(([k, v]) => `${k}=${v}`).join(' ');
  out(`# ${prog.chainNames.join(' <- ')}  (${prog.states.length} states, data ${prog.dataSize} bytes)`);
  if (legend) out(`# vars: ${legend}`);
  const name = prog.name.replace(/^C\d\d[A-Z]_/, '');
  const proc = world.spawn(prog, { name, ref: 1, vars: autoVars, construct: false });
  // act sequencer standing in for the native caretaker (ZFFCareTaker_<level>, not ported yet)
  const queue = [...acts];
  const careRef = autoVars.rCareTaker;
  if (careRef !== undefined) {
    world.commandHandlers.set(careRef, (cmd) => {
      if (/^CompletedAct$/i.test(cmd.name) && queue.length) {
        const next = queue.shift();
        world.after(actGap, () => world.send(proc, 'StartAct', [next], 'caretaker'));
      }
    });
  }
  proc.run(); // constructor
  if (queue.length) {
    const first = queue.shift();
    world.after(Math.max(0, at), () => world.send(proc, 'StartAct', [first], 'caretaker'));
  }
  for (let i = 0; i < ticks && !proc.terminated; i++) world.tick(dt);
  out(`# end t=${world.time.toFixed(2)} state=${proc.stateName} instructions=${proc.instructions}`);
  const miss = reg.missingReport();
  if (miss.length) out(`# stubbed natives called: ${miss.map(([k, n]) => `${k}x${n}`).join(' ')}`);
  return { world, proc, prog, lines, sends, states, natives, registry: reg };
}

function parseArgs(argv) {
  const o = { vars: {}, acts: [] };
  const pos = [];
  for (let i = 0; i < argv.length; i++) {
    const a = argv[i];
    if (a === '--act') o.acts.push(...argv[++i].split(',').map(Number));
    else if (a === '--at') o.at = Number(argv[++i]);
    else if (a === '--ticks') o.ticks = Number(argv[++i]);
    else if (a === '--dt') o.dt = Number(argv[++i]);
    else if (a === '--no-sim') o.sim = false;
    else if (a === '--all-natives') o.allNatives = true;
    else if (a === '--ops') o.ops = true;
    else if (a === '--var') { const [k, v] = argv[++i].split('='); o.vars[k] = Number(v); }
    else pos.push(a);
  }
  o.scriptsDir = pos[0]; o.script = pos[1];
  return o;
}

if (import.meta.url === `file://${process.argv[1]}`) {
  const o = parseArgs(process.argv.slice(2));
  if (!o.scriptsDir || !o.script) {
    console.error('usage: node script-vm/trace.mjs <scripts_dir> <script.ppo> [--act N[,N..]] [--ticks N] [--at SEC] [--dt SEC] [--no-sim] [--all-natives] [--ops] [--var NAME=VAL]');
    process.exit(2);
  }
  runTrace({ ...o, print: (s) => console.log(s) });
}
