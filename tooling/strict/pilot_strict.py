#!/usr/bin/env python3
"""pilot_strict.py - STRICT callee stubs for the decompilation pilot (a launcher + monkey patch; shared pilot.py is never changed).

    FF_STRICT_STUBS=1 python3 -I pilot_strict.py <path/to/a/folder's/harness/pilot.py> <the usual pilot.py arguments>

Without FF_STRICT_STUBS=1 it behaves exactly like pilot.py. With it, every call into a STUB while the original or the port runs under
Pilot.run is checked against what the ORIGINAL exe says (strict_truth.py), not against what the spec or the port declares:

  (a) per callee the pop count (`ret N`) and which of ECX/EDX it reads come from the original's disassembly at the callee address
      (direct callees: Python hooks and jmp-patched stubs at exe addresses); for stubs without an address (fake vtable slots, stub_fn,
      imports) from the original's CALL SITE: `add esp,N` after the call = cdecl with N/4 arguments, otherwise the dwords pushed in the
      chain before the call are the callee-popped arguments, and ECX is an input when the chain sets it.
  (b) on entry ECX/EDX (when the callee reads them / the site sets them), the argument words (their number comes from (a)) and the call
      kind (call vs tail jump) are logged; the PORT's log is compared with the ORIGINAL's, entry by entry. Stack addresses and pointers
      into the exe image or the port blob are tokens (they differ between the two runs by construction).
  (c) after a stub returns, ECX and EDX (only the ones the real callee clobbers) are overwritten with junk, in both runs, so a stale
      ECX cannot hide a missing `this`.
  (d) the pop count is the original's `ret N`, whatever the stub's handler passes to emu.ret().

On a mismatch the verify result gets the first strict difference in `why` plus three facts: `orig_stable` (the original gives the same
result with and without the strict stubs on that case: if False the strict machinery, not the port, is the suspect), `baseline`
(status of the same function with strict off) and `strict_notes` (spec stub declarations that contradict the original's call site).

Env: FF_STRICT_STUBS=1 on; FF_STRICT_NOJUNK=1 / FF_STRICT_NOARGS=1 / FF_STRICT_NOPOP=1 switch a part off (ablation).
FF_STRICT_SITE_CONTRACTS optionally names a JSON file with explicit, image-hash- and call-byte-checked arities for call sites; it is not original-only
inference and its use is listed in strict_notes.
"""
import importlib.util
import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
ON = os.environ.get('FF_STRICT_STUBS') == '1'
NOJUNK = os.environ.get('FF_STRICT_NOJUNK') == '1'
NOARGS = os.environ.get('FF_STRICT_NOARGS') == '1'
NOPOP = os.environ.get('FF_STRICT_NOPOP') == '1'

BLOB_BASE = 0x31000000
STACK_LO, STACK_HI = 0x0ff00000 - 0x100000, 0x0ff00000
HEAP_LO, HEAP_HI = 0x20000000, 0x21000000
TRAMP = 0x7e000000 + 0x800        # inside the reserved first page of the stub area: never handed out by _new_stub
MAXW = 8


def hx(v):
    return 'None' if v is None else '0x%x' % v


class State:
    def __init__(self, emu):
        self.emu = emu
        self.enabled = ON
        self.testing = False
        self.side = None
        self.fn = None
        self.log = []
        self.ords = {}
        self.stack = []             # [(ra, ctx)]
        self.ref = None             # the original's log for this case (while the port runs)
        self.orig_logs = {}         # fn -> log of the last original run
        self.junk_n = 0
        self.hooks = []
        self.notes = []
        self.armed = False
        self.blob_end = 0

    def norm(self, v):
        if STACK_LO <= v < STACK_HI:
            return 'S'
        e = self.emu
        if e.base <= v < e.base + len(e.image) or BLOB_BASE <= v < self.blob_end:
            return 'P'
        return v


def install(pe_emu, pilot):
    from strict_truth import truth, EXE
    T = truth()
    from capstone.x86_const import X86_OP_MEM, X86_OP_REG
    # Optional, explicit fixture contracts are never inferred from a port.
    # They apply only to the named original image and instruction bytes.
    site_contracts = {}
    contract_file = os.environ.get('FF_STRICT_SITE_CONTRACTS')
    if contract_file:
        with open(contract_file) as f:
            contract = json.load(f)
        with open(EXE, 'rb') as f:
            image_sha = hashlib.sha256(f.read()).hexdigest()
        if image_sha != contract['exe_sha256']:
            raise ValueError('site contracts do not match the original executable')
        for item in contract['sites']:
            site, function = int(item['site'], 16), int(item['function'], 16)
            expected = bytes.fromhex(item['bytes'])
            instructions, byaddr, _ = T.func(function)
            if site not in byaddr or T.read(site, len(expected)) != expected:
                raise ValueError('site contract instruction mismatch at %s' % hx(site))
            ins = instructions[byaddr[site]]
            if (ins.mnemonic != 'call' or len(expected) != ins.size or not ins.operands
                    or ins.operands[0].type not in (X86_OP_MEM, X86_OP_REG)):
                raise ValueError('site contract must name a complete indirect call instruction')
            words = item['words']
            if type(words) is not int or not 0 <= words <= MAXW:
                raise ValueError('invalid site contract word count')
            key = (function, site + ins.size)
            if key in site_contracts:
                raise ValueError('duplicate site contract at %s' % hx(site))
            site_contracts[key] = (words, item.get('evidence', 'explicit fixture'))
    PEEmu = pe_emu.PEEmu
    from unicorn import UC_HOOK_CODE
    from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_ECX, UC_X86_REG_EDX

    o_init, o_run, o_ret = PEEmu.__init__, PEEmu._run, PEEmu.ret
    o_stub, o_real = PEEmu._on_stub_code, PEEmu._on_real_code

    def init(self, *a, **k):
        o_init(self, *a, **k)
        self._st = State(self)
        self.stubs[TRAMP] = ('<strict-return>', None)    # never stops: handled in on_stub before the table lookup
        self.mu.mem_write(TRAMP, b'\xc3')
    PEEmu.__init__ = init

    def preserved_words(cs, ra):
        """Recognize a narrow, straight-line retained word consumed by the next callee.

        Require: a clean initial push chain; one push and register-only moves;
        a known ret-8 direct callee; then two saved-register pops and function
        return. This does not infer general indirect callee arity.
        """
        if not cs or not cs.get('certain') or not cs.get('clean') or cs.get('capture') or cs.get('cleanup') or cs.get('pushes') != 2:
            return 0
        fe = cs.get('func')
        if fe is None:
            return 0
        ins, byaddr, labels = T.func(fe)
        j = byaddr.get(ra)
        if j is None or j + 5 >= len(ins):
            return 0
        a, b, call, pop1, pop2, ret = ins[j:j+6]
        if (a.address != ra or a.mnemonic != 'push' or a.op_str != 'eax'
                or b.mnemonic != 'mov' or b.op_str != 'ecx, esi'
                or call.mnemonic != 'call' or pop1.mnemonic != 'pop' or pop1.op_str != 'esi'
                or pop2.mnemonic != 'pop' or pop2.op_str != 'ebp' or ret.mnemonic != 'ret'):
            return 0
        if any(x.address in labels for x in (b, call, pop1, pop2, ret)):
            return 0
        target = T.imm_target(call)
        if target is None:
            return 0
        callee = T.callee(target)
        if not callee['known'] or callee['mixed'] or callee['pop'] != 8:
            return 0
        return 1

    # ------------------------------------------------------------------ entry / return
    def enter(self, ident, direct, native=False):
        """Called when execution reaches a stub. ident: callee address (direct) or stub address."""
        st = self._st
        if not (st.testing and st.armed):
            return
        esp = self.reg('esp')
        ra = self.r32(esp)
        words = [self.r32(esp + 4 + 4 * i) for i in range(MAXW)]
        ecx, edx = self.reg('ecx'), self.reg('edx')
        tail = ra in (self.RET_ADDR, getattr(self, 'RET_ST0', -1), self.RET_FLOAT)
        k = st.ords.get(ident, 0)
        st.ords[ident] = k + 1
        if native and k >= 64:
            return                  # hot native helper: the first 64 calls are enough
        ctx = {'id': ident, 'k': k, 'esp': esp, 'tail': tail, 'ecx': ecx, 'edx': edx, 'words': words, 'direct': direct,
               'pop': None, 'n': None, 'ck_ecx': False, 'ck_edx': False, 'junk': ('ecx', 'edx'), 'decl': None, 'site': None, 'conf': True, 'native': native}
        if st.side == 'orig':
            ce = T.callee(ident) if direct and ident < 0x1000000 else None
            cs = None if tail else T.callsite(ra)
            ctx['site'] = cs
            pop = n = None
            conf = True
            if direct and ce is not None and ce['known']:
                if ce['pop'] > 0:
                    pop, n = ce['pop'], ce['pop'] // 4
                elif cs is not None and cs['cleanup'] > 0:
                    pop, n = 0, cs['cleanup'] // 4
                elif cs is not None and cs['kind'] != 'none':
                    pop, n = 0, 0          # `ret` without an add esp after the call: thiscall without stack args, or a deferred cdecl cleanup (not told apart)
                ctx['ck_ecx'] = 'ecx' in ce['reads'] and (cs is None or cs['kind'] != 'none' or tail)
                ctx['ck_edx'] = 'edx' in ce['reads'] and (cs is None or cs['kind'] != 'none' or tail)
                ctx['junk'] = tuple(r for r in ('ecx', 'edx') if r in ce['writes'])
                ctx['zero'] = tuple(r for r in ('ecx', 'edx') if r not in ce['reads'] and r not in ce.get('pushed', ()))      # not an input of the real callee: a recorder must not see stale values
            elif cs is not None and cs['kind'] != 'none':
                if cs['cleanup'] > 0 and not cs['capture']:
                    pop, n = 0, cs['cleanup'] // 4
                elif cs['certain']:
                    n = cs['pushes'] - preserved_words(cs, ra)  # account for narrowly proven retained word
                    pop = None                                 # a callee-pop of a virtual slot cannot be told from pushes meant for a later call: the spec's declaration stays (limitation, see strict-stubs.md)
                ctx['ck_ecx'] = bool(cs['ecx_set']) and cs['certain']
            if tail and direct and ce is not None and ce['known']:
                pop = ce['pop']
                n = pop // 4
            override = site_contracts.get((st.fn, ra))
            if override and not direct and cs is not None:
                n = override[0]
                st.notes.append('explicit fixture site-arity contract at %s: %s' % (hx(ra), override[1]))
            ctx['pop'], ctx['n'], ctx['conf'] = pop, n, conf
        else:
            ref = st.ref[0] if st.ref is not None else None
            e = None
            if ref is not None:
                cands = [x for x in ref if x['id'] == ident]
                if k < len(cands):
                    e = cands[k]
            if e is not None:
                ctx.update(pop=e['pop'], n=e['n'], ck_ecx=e['ck_ecx'], ck_edx=e['ck_edx'], junk=e['junk'], conf=e['conf'], zero=e.get('zero', ()))
            else:
                ctx['n'] = 0
                ctx['extra'] = True
        if not native and not NOJUNK:
            ctx['zsave'] = {}
            for r in ctx.get('zero', ()):
                ctx['zsave'][r] = ecx if r == 'ecx' else edx
                self.mu.reg_write(UC_X86_REG_ECX if r == 'ecx' else UC_X86_REG_EDX, 0)
        if not native and not NOJUNK:
            pass
        self._strict_cur = ctx
        if tail:
            ctx['n'] = ctx['n'] if ctx['n'] is not None else 0
            ctx['popdiff'] = None
            ctx['decl_pop'] = None
            finalize(self, ctx)          # a tail jump returns to the harness: nothing to junk, log it now
            self._strict_cur = ctx
            return
        # watch the return address with a code hook; the stack is left alone (spec stubs identify call sites by [esp])
        def cb(mu, a, s, u, ctx=ctx):
            if ctx.get('done') or self.reg('esp') < ctx['esp'] + 4:
                return
            ctx['done'] = True
            mu.hook_del(ctx['hk'])
            ctx['popdiff'] = None if ctx['pop'] is None else self.reg('esp') - (ctx['esp'] + 4 + ctx['pop'])
            finalize(self, ctx)
            if st.stack and st.stack[-1][1] is ctx:
                st.stack.pop()
        st.stack.append((ra, ctx))
        ctx['hk'] = self.mu.hook_add(UC_HOOK_CODE, cb, begin=ra, end=ra)

    def finalize(self, ctx):
        st = self._st
        ra = None
        n = ctx['n']
        if n is None:       # uncertain truth for a stub without address: fall back to the declaration the handler used
            d = ctx['decl']
            n = 0 if d is None else d // 4
            ctx['n'] = n
        ctx['decl_pop'] = ctx['decl']
        if st.side == 'orig' and ctx['decl'] is not None and ctx['pop'] is not None and ctx['conf'] and ctx['decl'] != ctx['pop'] \
                and ctx['site'] is not None:
            st.notes.append('stub %s declared pop %d, original pops %d' % (hx(ctx['id']), ctx['decl'], ctx['pop']))
        if ctx.get('popdiff') and not NOPOP and st.side == 'orig' and not ctx['native']:
            st.notes.append('stub %s left esp %+d vs the original callee' % (hx(ctx['id']), ctx['popdiff']))
        args = tuple(st.norm(w) for w in ctx['words'][:n]) if not NOARGS else ()
        ctx['entry'] = (ctx['id'], 'tail' if ctx['tail'] else 'call', st.norm(ctx['ecx']) if ctx['ck_ecx'] else None,
                        st.norm(ctx['edx']) if ctx['ck_edx'] else None, args, None)      # popdiff is reported in strict_notes only
        st.log.append(ctx)
        if not NOJUNK and not ctx['native'] and not ctx['tail']:
            for r, v in ctx.get('zsave', {}).items():          # the zero was only for the handler: the original callee did not touch it
                if r not in ctx['junk']:
                    self.mu.reg_write(UC_X86_REG_ECX if r == 'ecx' else UC_X86_REG_EDX, v)
            for r in ctx['junk']:
                st.junk_n += 1
                self.mu.reg_write(UC_X86_REG_ECX if r == 'ecx' else UC_X86_REG_EDX, 0xe1c00000 | (st.junk_n << 4) | (1 if r == 'ecx' else 2))
        self._strict_cur = None

    # ------------------------------------------------------------------ patched dispatch
    def on_stub(self, mu, addr, size, user):
        st = self._st
        s = self.stubs.get(addr)
        if s is not None and s[1] is not None and addr != TRAMP and self._cur is not None and addr != self.RET_ADDR:
            enter(self, addr, False)
            try:
                return o_stub(self, mu, addr, size, user)
            finally:
                self._strict_cur = None
        return o_stub(self, mu, addr, size, user)
    PEEmu._on_stub_code = on_stub

    def on_real(self, mu, addr, size, user):
        h = self.hooks.get(addr)
        if h is not None and self._cur is not None:
            enter(self, addr, True)
            try:
                return o_real(self, mu, addr, size, user)
            finally:
                self._strict_cur = None
        return o_real(self, mu, addr, size, user)
    PEEmu._on_real_code = on_real

    def ret(self, eax=None, argbytes=0, st0=None):
        c = getattr(self, '_strict_cur', None)
        if c is not None:
            c['decl'] = argbytes
            if c['pop'] is not None and c['conf'] and not NOPOP:
                argbytes = c['pop']
            elif c['pop'] is not None and not c['conf'] and False:
                pass
        return o_ret(self, eax=eax, argbytes=argbytes, st0=st0)
    PEEmu.ret = ret

    def run(self, addr, esp, this, regs, stop_at, max_insns, float_ret):
        st = self._st
        if not (st.enabled and st.testing and not st.armed):
            return o_run(self, addr, esp, this, regs, stop_at, max_insns, float_ret)
        st.armed = True
        st.side = 'port' if addr >= BLOB_BASE else 'orig'
        inv = {v: k for k, v in getattr(self, 'decomp', {}).items()}
        st.fn = inv.get(addr, addr) if st.side == 'port' else addr
        st.log, st.ords, st.stack = [], {}, []
        if st.side == 'orig':
            st.orig_logs.pop(st.fn, None)
        st.blob_end = BLOB_BASE + getattr(self, 'blob_size', 0)
        st.junk_n = 0
        st.ref = [st.orig_logs.get(st.fn)] if st.side == 'port' and st.fn in st.orig_logs else None
        # jmp-patched machine-code stubs at exe addresses the function calls (or tail-jumps to)
        for h in st.hooks:
            self.mu.hook_del(h)
        st.hooks = []
        seen = set()
        try:
            fe = T.func(st.fn)
            for i in fe[0]:
                t = T.imm_target(i) if i.mnemonic in ('call', 'jmp') else None
                if t is None or t in fe[1] or t in self.hooks or t in seen or not (self.base <= t < self.base + 0x300000):
                    continue
                seen.add(t)
                cur = bytes(self.mu.mem_read(t, 5))
                native = not (cur != T.read(t, 5) and cur[:1] == b'\xe9')       # a jmp-patched stub replaced the real code
                def cb(mu, a, s, u, t=t, native=native):
                    if self._cur is not None and st.armed:
                        enter(self, t, True, native)
                st.hooks.append(self.mu.hook_add(UC_HOOK_CODE, cb, begin=t, end=t))
        except Exception as ex:           # analysis problems must never change a result
            st.notes.append('truth error %r' % (ex,))
        try:
            return o_run(self, addr, esp, this, regs, stop_at, max_insns, float_ret)
        finally:
            for h in st.hooks:
                self.mu.hook_del(h)
            st.hooks = []
            for _ra, c in st.stack:
                if not c.get('done') and c.get('hk') is not None:
                    try:
                        self.mu.hook_del(c['hk'])
                    except Exception:
                        pass
            st.stack = []
            st.armed = False
    PEEmu._run = run

    # ------------------------------------------------------------------ Pilot.run: attach the verdict to the result dict
    Pilot = getattr(pilot, 'Pilot', None)
    if Pilot is None:
        for v in vars(pilot).values():
            if isinstance(v, type) and issubclass(v, PEEmu) and v is not PEEmu and 'run' in vars(v):
                Pilot = v
                break
    if Pilot is None:
        raise SystemExit('STRICT-UNSUPPORTED: this folder\'s pilot has no PEEmu subclass with run()')
    o_prun = Pilot.run

    def fmt(v):
        return v if isinstance(v, str) else hx(v)

    def isjunk(v):
        return isinstance(v, int) and (v in (0xcccccccc, 0x5151515, 0xd0d0d0d, 0xb0b0b0b) or (v & 0xfff00000) == 0xe1c00000)

    def wild(x, y):
        """A value the ORIGINAL itself left uninitialised (fill pattern, register sentinel, strict junk) is not an input the port must reproduce."""
        x, y = list(x), list(y)
        for k in (2, 3):
            if isjunk(x[k]):
                y[k] = x[k]
        if len(x[4]) == len(y[4]):
            ya = list(y[4])
            for j, v in enumerate(x[4]):
                if isjunk(v):
                    ya[j] = v
            y[4] = tuple(ya)
        return tuple(x), tuple(y)

    def compare(ref, log):
        if ref is None:
            return None
        rk = {(c['id'], c['k']) for c in ref if c['native']}
        lk = {(c['id'], c['k']) for c in log if c['native']}
        a = [c for c in ref if not c['native'] or (c['id'], c['k']) in lk]       # a native helper only one side calls is not a stub
        b = [c for c in log if not c['native'] or (c['id'], c['k']) in rk]
        for i in range(max(len(a), len(b))):
            if i >= len(a):
                return 'call#%d port has an extra call to %s' % (i, hx(b[i]['id']))
            if i >= len(b):
                return 'call#%d port never calls %s (orig does)' % (i, hx(a[i]['id']))
            x, y = a[i]['entry'], b[i]['entry']
            x, y = wild(x, y)
            if x == y:
                continue
            if x[0] != y[0]:
                return 'call#%d callee orig=%s port=%s' % (i, hx(x[0]), hx(y[0]))
            nm = hx(x[0]) + ('(native)' if a[i]['native'] else '')
            if x[1] != y[1] and not (x[1] == 'call' and y[1] == 'tail'):      # port jmp where the original calls: clang -O2 tail-call merge
                return 'call#%d %s orig=%s port=%s' % (i, nm, x[1], y[1])
            if x[2] != y[2]:
                return 'call#%d %s ecx orig=%s port=%s' % (i, nm, fmt(x[2]), fmt(y[2]))
            if x[3] != y[3]:
                return 'call#%d %s edx orig=%s port=%s' % (i, nm, fmt(x[3]), fmt(y[3]))
            if x[4] != y[4]:
                nn = a[i]['n']
                tag = 'args-permuted' if sorted(map(str, x[4])) == sorted(map(str, y[4])) else 'args'
                return 'call#%d %s %s(n=%d) orig=%s port=%s' % (i, nm, tag, nn, [fmt(v) for v in x[4]], [fmt(v) for v in y[4]])
            if x[5] != y[5]:
                return 'call#%d %s popdiff orig=%s port=%s' % (i, nm, x[5], y[5])
        return None

    def prun(self, addr, *a, **k):
        st = self._st
        if not st.enabled:
            return o_prun(self, addr, *a, **k)
        st.testing = True
        st.armed = False
        try:
            out = o_prun(self, addr, *a, **k)
        finally:
            st.testing = False
        if st.side is None or not st.armed and not st.log and st.fn is None:
            pass
        if st.side == 'orig':
            st.orig_logs[st.fn] = list(st.log)
            out['strict'] = 'ok'
            st.run_notes = list(st.notes)
        elif st.side == 'port':
            d = compare(st.ref[0] if st.ref else None, st.log)
            out['strict'] = 'ok' if d is None else d
        st.armed = False
        if os.environ.get('FF_STRICT_DEBUG') and st.side:
            st.dbg = getattr(st, 'dbg', 0) + 1
            if st.dbg <= int(os.environ['FF_STRICT_DEBUG']):
                sys.stderr.write('[%s fn=%s]\n' % (st.side, hx(st.fn)))
                for c in st.log:
                    s = c['site']
                    sys.stderr.write('   %s %s n=%s pop=%s decl=%s conf=%s ck=%s/%s junk=%s entry=%s site=%s\n' % (
                        hx(c['id']), 'tail' if c['tail'] else 'call', c['n'], c['pop'], c['decl'], c['conf'], c['ck_ecx'], c['ck_edx'], c['junk'],
                        c['entry'][2:], None if s is None else {k: s[k] for k in ('kind', 'pushes', 'cleanup', 'certain', 'capture', 'clean')}))
        return out
    Pilot.run = prun

    # ------------------------------------------------------------------ verify: facts about a failure
    o_verify = pilot.verify

    def verify(emu, spec, n, seed, *va, **vk):
        st = emu._st
        st.notes = []
        st.run_notes = []
        audit = []
        original_results = {}
        chosen = []
        original_one_run = pilot.one_run
        original_diff = pilot.diff
        if os.environ.get('FF_AUDIT_CASES') == '1':
            def audited_one_run(em, sp, addr, abi, seed_value, case):
                context, result = original_one_run(em, sp, addr, abi, seed_value, case)
                if addr == sp.addr:
                    info = (pilot.fmt_args(context), result.get('fault'), case)
                    audit.append(info)
                    # Retain the actual object through redraw attempts; verify() may
                    # choose the first result after exhausting redraws.
                    original_results[id(result)] = (result, info)
                return context, result
            def audited_diff(orig, port):
                match = original_results.get(id(orig))
                chosen[:] = [match[1]] if match and match[0] is orig else []
                original_results.clear()
                return original_diff(orig, port)
            pilot.one_run = audited_one_run
            pilot.diff = audited_diff
        try:
            r = o_verify(emu, spec, n, seed, *va, **vk)
        finally:
            pilot.one_run = original_one_run
            pilot.diff = original_diff
        if audit and r.get('status') == 'mismatch':
            if chosen and chosen[0][0] == r.get('args'):
                _, fault, selected_case = chosen[0]
                r['audited_original_faults'] = [fault if fault is not None else '<no fault>']
                r['audited_matching_cases'] = [selected_case]
                r['audited_match_method'] = 'selected-result-identity'
            else:
                matching = [(fault, case) for args, fault, case in audit if args == r.get('args')]
                r['audited_original_faults'] = sorted({fault if fault is not None else '<no fault>' for fault, _ in matching})
                r['audited_matching_cases'] = [case for _, case in matching][-8:]
                r['audited_match_method'] = 'visible-arguments-fallback'
        notes = sorted(set(st.notes))[:6] + sorted(set(getattr(st, 'run_notes', []) or []))[:0]
        if notes:
            r['strict_notes'] = notes
        if r.get('status') == 'mismatch':
            case = r.get('audited_matching_cases', [r.get('cases', 1) - 1])[0] if r.get('audited_match_method') == 'selected-result-identity' else r.get('cases', 1) - 1
            # a) does the strict machinery change the original itself on that case?
            try:
                st.enabled = True
                _, o1 = pilot.one_run(emu, spec, spec.addr, spec.abi, seed, case)
                st.enabled = False
                _, o0 = pilot.one_run(emu, spec, spec.addr, spec.abi, seed, case)
                core = ('fault', 'eax', 'edx', 'st0', 'xmm0', 'pop', 'clobbered', 'x87_top')
                r['orig_stable'] = all(o0.get(k) == o1.get(k) for k in core)
                r['orig_rec_changed'] = o0.get('heap') != o1.get('heap') or o0.get('calls') != o1.get('calls') or o0.get('data') != o1.get('data')
                if not r['orig_stable']:
                    r['orig_diff'] = ['%s strict-off=%s strict-on=%s' % (k, repr(o0.get(k))[:90], repr(o1.get(k))[:90]) for k in core if o0.get(k) != o1.get(k)][:4]
                # b) baseline: same function, strict off
                bl = o_verify(emu, spec, n, seed, *va, **vk)
                r['baseline'] = bl['status']
                if bl['status'] == 'mismatch':
                    r['baseline_why'] = bl.get('why', '')[:200]
            except Exception as ex:
                r['orig_stable'] = 'error %r' % (ex,)
            finally:
                st.enabled = ON
        return r
    pilot.verify = verify


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    path = os.path.abspath(sys.argv[1])
    sys.argv = [path] + sys.argv[2:]
    hdir = os.path.dirname(path)
    sys.path.insert(0, hdir)
    import pe_emu       # tooling/pe_emu.py (next to pilot.py); pilot.py imports the same module object
    spec = importlib.util.spec_from_file_location('pilot', path)
    pilot = importlib.util.module_from_spec(spec)
    sys.modules['pilot'] = pilot
    spec.loader.exec_module(pilot)
    if ON:
        install(pe_emu, pilot)
    sys.exit(pilot.main())


if __name__ == '__main__':
    main()
