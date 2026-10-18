"""specs_s250600.py - w3i hand spec for 0x5f56f0 (batch 234025 lifted port, w3g): universal fake-object graph.
Every vtable slot / direct callee is a generic stub. The callee-pop of each call site comes from the original's call table
(callpops_5f56f0.json, return address -> pop bytes, from espmap); the PORT run replays the pops the original run recorded (call k pops the
same as call k of the original), so a wrong arity in the port shows up as a stack mismatch instead of being hidden by the stub."""
import json, os, struct as _st
from pilot import S, F
from recruits_util import rnd, clear_hooks, _HOOKED, hook_rec

LOGN = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'logn_5f56f0.json'))).items()}
POPS = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callpops_5f56f0.json'))).items()}
KINDS = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callkinds_5f56f0.json'))).items()}
SLO, SHI = 0x0fe00000, 0x0ff00000
GOODS = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'good_5f56f0.json'))) if os.path.exists(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'good_5f56f0.json')) else [0]
ST0S = set(json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'st0sites_5f56f0.json'))))
ST = {'n': 0, 'rec': [], 'k': 0, 'phase': 0}
SLOTS = [0, 4, 8, 12, 16, 20, 24, 28, 36, 40, 166]
DIRECT = [5243632, 5243744, 5298096, 6239296, 6241264, 6241344, 6241600, 6241712, 6242240, 6242480, 6242576, 6243216, 6244864, 6244992, 6245056, 6245760, 6245824, 6245888, 6245984, 6246080, 6246144, 6246256, 6246320, 6246384, 6246432, 6246880, 6246992, 6247152, 6247312, 6247408, 6247568, 6247712, 6247968, 6248064, 6262800, 6262944, 6263088, 6263392, 6268464, 6273792, 6290176, 6293504, 6302928, 6506096]
OFFS = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'offs_5f56f0.json')))


def g5f56f0(c):
    clear_hooks(c)
    e = c.emu
    import random as _random
    if os.environ.get('W3I_SCAN'):
        r = _random.Random(777000 + c.case)           # scan mode: candidate parameter seeds, ignoring the harness seed
    else:
        _k = c.rng.getrandbits(32)                    # normal mode: draw a recorded NON-FAULTING parameter seed (rejection sampling of valid manager states)
        r = _random.Random(GOODS[_k % len(GOODS)])
    ST['phase'] ^= 1          # alternates original (1) / port (0) run of the same case
    orig = ST['phase'] == 1
    if orig:
        ST['rec'] = []
        ST['logn'] = []
        ST['esp_o'] = []
        ST['ra_o'] = []
    else:
        ST['esp_m'] = []
        ST['popmis'] = []
    ST['k'] = 0
    pool = []
    THIS_ = [0]
    MEMO = {}
    SITEMEMO = r.random() < float(os.environ.get("W3I_SITEMEMO", "0.3"))     # half of the cases: a getter returns independent values at different call sites
    PN = r.choice([0.05, 0.2, 0.4, 0.6])     # per-case null probability of pointer returns
    PZ = r.choice([0.2, 0.4, 0.6])           # per-case zero probability of unknown / arg returns
    try:
        e.mu.mem_map(0, 0x10000)    # small integers used as pointers read zeros (same on both sides)
    except Exception:
        pass

    def newobj(n=0x900):
        o = e.alloc(n, 4)
        pool.append(o)
        return o
    GB = bytes(r.choice([0, 0, 1, 0xCC, r.randrange(256)]) for _ in range(0x120))
    e.wbytes(0x20201000, GB)
    ST['GB'] = GB
    if not getattr(e, '_w3i_gb_hook', False):
        from unicorn import UC_HOOK_CODE
        e.mu.hook_add(UC_HOOK_CODE, lambda uc, a, sz, u: e.wbytes(e.reg('ebp') - 0x11c, ST['GB'][:0x114]), begin=0x5f5705, end=0x5f5705)   # after the two register saves
        e._w3i_gb_hook = True
    import pe_emu as _pe
    from unicorn.x86_const import UC_X86_REG_XMM0
    from unicorn.x86_const import UC_X86_REG_FP0
    for _i in range(8):
        e.mu.reg_write(UC_X86_REG_FP0 + _i, (0, 0))
    for _i in range(8): e.mu.reg_write(UC_X86_REG_XMM0 + _i, 0)     # w3i: xmm0-7 survive from the previous case (the function reads uninitialised xmm registers): zero them
    e.wbytes(_pe.STACK_TOP - 0x10200, bytes(0x10000))      # w3i: zero the stack area below the entry frame: stale bytes of the previous case made the original's outcome depend on case order
    e.wbytes(0x20202020, bytes(0x40000))      # w3i: zero the heap region the spec uses: reads past an object otherwise see the previous case (state leak: orig outcomes depended on case order)
    e._heap_next = 0x20202020     # vtable at 0x20202020: a low-page 'object' read at ANY alignment yields the same vtable pointer
    vt = e.alloc(0x800, 4)
    for _ in range(6):
        newobj()

    def val(depth=0):
        x = r.random()
        if x < 0.25: return 0
        if x < 0.4: return 1
        if x < 0.5: return r.choice([2, 3, 4, 7, 8, 0x10, 0xff])
        if x < 0.6: return r.randrange(0, 0x8000)
        return r.choice(pool)

    def kval(k):
        kind, consts, nullable = k
        if kind == 'ptr': return 0 if r.random() < (PN if nullable else PN / 3) else ((1 if r.random() < (0.4 if consts else 0.08) else r.choice(pool)))
        if kind == 'int': return r.choice(consts + [x + 1 for x in consts] + [x - 1 for x in consts] + consts + [0])
        if kind == 'bool': return r.choice([0, 1])
        if kind == 'arg': return 0 if r.random() < PZ else r.choice(pool + [1, 2])
        return 0 if r.random() < PZ else val()

    def stub(name):
        def h(em, res_=None):
            esp = em.reg('esp')
            ra = em.r32(esp)
            if orig:
                pop = POPS.get(ra, 0)
                if name.startswith('s') and os.environ.get('W3I_DYNPOP', '1') == '1' and pop > 0:
                    pop = max(0, (em.reg('ebp') - 0x124 - esp) - 4)     # outstanding pushes at an indirect call (ebp frame, 0x78 locals + 3 saved registers): the callee consumes them all
                    ST.setdefault('dyn', {}).setdefault(hex(ra), set()).add(pop)
                mk_ = (name, em.reg('ecx') if name.startswith('s') else em.r32(esp + 4), tuple(KINDS.get(ra, ['unk', [], False])[1]), ra if SITEMEMO else 0, em.r32(esp + 4) if pop >= 4 else 0)
                if ra == 0x58d7db:      # list walk (next node): fresh values, ends with a null after a few steps
                    rv = 0 if r.random() < 0.45 else r.choice(pool)
                elif mk_ in MEMO:
                    rv = MEMO[mk_]       # getters are idempotent: the same slot on the same object returns the same value
                else:
                    rv = MEMO[mk_] = (r.choice(STRS) if name == 's0' else kval(KINDS.get(ra, ['unk', [], False])))
                fills = [[(r.choice(pool) if r.random() < 0.3 else (r.choice([0, 1, 1, 2, 3, 4]) if r.random() < 0.3 else _st.unpack('<I', _st.pack('<f', r.choice([r.uniform(-3, 3), r.uniform(-3, 3), 0.0, 160.0, 210.0, 900.0, 50000.0, 2000000.0, r.uniform(0, 300)])))[0])) for q in range(4)] + [r.choice(pool + [0, 0]), r.getrandbits(1)] for i in range(6)]
                eff = r.random() < 0.3
                st0v = r.choice([0.0, 0.25, 0.5, 1.0, 2.0, r.uniform(0, 10)]) if ra in ST0S else None
                if ra == 0x58d320 and r.random() < 0.4: rv = THIS_[0]      # the controller returned by slot 0x2f4 is sometimes the manager itself
                ST['rec'].append((pop, rv, fills, eff, st0v))
                ST.setdefault('logn', []).append(LOGN.get(ra, 0))
            else:
                pop, rv, fills, eff, st0v = ST['rec'][ST['k']] if ST['k'] < len(ST['rec']) else (0, 0, [[0] * 6] * 6, False, None)
            ST.setdefault('esp_o' if orig else 'esp_m', []).append(esp)
            if orig: ST.setdefault('ra_o', []).append((hex(ra), name, POPS.get(ra, 0)))
            if not orig: ST.setdefault('ra_esp', {}).setdefault(ra, {}).setdefault(esp, []).append(ST['k'])
            if not orig:
                b_ = bytes(em.rbytes(ra, 6))
                n_ = b_[2] if b_[:2] == b'\x83\xec' else (int.from_bytes(b_[2:6], 'little') if b_[:2] == b'\x81\xec' else None)
                if n_ is not None and n_ != pop:
                    ST.setdefault('popmis', []).append((ST['k'], name, hex(ra), n_, pop))
            if os.environ.get('W3I_DBG') and ra == 0x58d3f9: print('S58', hex(ra), 'rv', hex(rv), 'pop', pop, 'k', ST['k'], 'arg', hex(em.r32(esp + 4)), 'ecx', hex(em.reg('ecx')), 'orig', orig, [kk for kk in MEMO if kk[0] == 's58'][:3])
            if os.environ.get('W3I_DBG') and ra == 0x58dcd9: print('S90', hex(esp), 'F5', fills[1][5], len(fills[1]), [hex(em.r32(esp + 4 + 4 * i)) for i in range(2)], [hex(x) for x in fills[1][:3]], pop)
            ST['k'] += 1
            if os.environ.get('W3I_DBG') and name == 'd59a580': print('59A580', 'orig' if orig else 'port', hex(esp), [hex(em.r32(esp + 4 * i)) for i in range(1, 4)])
            ec_ = em.reg('ecx')
            LS_ = (ST['logn'][ST['k'] - 1] if 0 < ST['k'] <= len(ST['logn']) else 0) > 0
            tag_ = ec_ if (name.startswith('s') and not LS_) else ((('T', ec_ - THIS_[0]) if THIS_[0] <= ec_ < THIS_[0] + 0x1000 else (ec_ if ec_ in pool else 0)) if name.startswith('d') else 0)
            row = [name, tag_] + [em.r32(esp + 4 + 4 * i) for i in range(min(pop // 4, 6))]
            if name == 'd4cc850': row = [name, ec_, em.reg('edx')]     # fastcall(ecx = string, edx = literal)
            if LS_:
                nl_ = ST['logn'][ST['k'] - 1] if 0 <= ST['k'] - 1 < len(ST['logn']) else 0
                row += [em.r32(esp + 4 + 4 * i) for i in range(nl_)]
            for i in range(min(pop // 4, 6)):
                v = row[2 + i]
                if SLO <= v < SHI:     # stack buffer: log what the function computed, then fill it with the callee's output
                    row[2 + i] = ('S',) + tuple(em.r32(v + 4 * q) for q in range(2))
                    for q in range(3):
                        em.w32(v + 4 * q, fills[i][q])
                    if v & 3:      # a byte / bool out parameter (unaligned stack address): 0 or 1
                        em.wbytes(v, bytes([fills[i][5]]))
                    if name == 'd596710':     # the callee fills a 0x48-byte record whose dword at +0x39 (unaligned) is an object pointer
                        for q in range(4, 18):
                            em.w32(v + 4 * q, fills[i][q % 4])
                        em.w32(v + 0x39, fills[i][4])
            if name.startswith('d') and name != 'd4cc850':      # register arguments (fastcall / thiscall) that point into the caller's stack are output buffers: log and fill them
                for j_, rg_ in enumerate(('ecx', 'edx')):
                    if rg_ == 'edx' and name not in ('d43e920', 'd43e960', 'd441940', 'd4419f0', 'd4de480'): continue
                    v_ = em.reg(rg_)
                    if SLO <= v_ < SHI:
                        row.append((rg_, 'S') + tuple(em.r32(v_ + 4 * q) for q in range(2)))
                        for q in range(3): em.w32(v_ + 4 * q, fills[4 + j_][q])
            em.calllog.append(tuple(row))
            if name == 's0' and orig: rv = ST['rec'][-1][1] if False else rv
            if LS_:       # the cdecl logger formats its message into the caller's buffer (arg 1): deterministic content
                bp = em.r32(esp + 8)
                if os.environ.get('W3I_DBG'): print('LOGGER', 'orig' if orig else 'port', hex(esp), [hex(em.r32(esp + 4 * i)) for i in range(1, 6)])
                if SLO <= bp < SHI:
                    em.wbytes(bp, b'log message\0' + bytes(0x30))
            if eff and name in ('d594540', 'd470550', 'd589c20', 'd5afc70', 's2f0'):
                em.w32(THIS_[0] + 0x836, 1)     # the callee sets a state word of the manager
            em.ret(eax=rv, argbytes=pop, st0=st0v)
        return h
    e.mu.mem_write(0, _st.pack('<I', vt) * (0x10000 // 4))   # a small integer used as an object pointer reads vtable-valued words
    STRS = []
    for t_ in (b'a\0', b'0123456789abcdef\0', b'Entity01\0'):
        a_ = e.alloc(len(t_), 4); e.wbytes(a_, t_); STRS.append(a_)
    for off in SLOTS:
        e.w32(vt + off, e.stub_fn('s%x' % off, stub('s%x' % off)))
    for o in pool:
        words = [val() for _ in range(0x900 // 4)]
        e.wbytes(o, b''.join(_st.pack('<I', w) for w in words))
        e.w32(o, vt)
        e.w32(o + 4, r.choice([0x6acac0, 0x6acacc, 0x6acb04, 0x6acb04, 0x6acb04, 0x6acb04, 0x6acac0, 0x6acacc, 0x67c8e8, 0]))   # the name string compared with the exe literals at 0x58f29d / 0x58f4cb / 0x58fd42 / 0x58fe67
    e.hook(0x633654, lambda em, res_=None: (em.calllog.append(('gs',)), print('GS eax', hex(em.reg('eax'))) if os.environ.get('W3I_DBG') else None, em.ret(argbytes=0)))     # /GS check: preserves eax like the real routine
    _HOOKED.add(0x633654)
    for a in DIRECT:
        e.hook(a, stub('d%x' % a)); _HOOKED.add(a)
    def _stricmp(em, res_=None):       # cdecl _stricmp (api-ms-win-crt-string import, IAT 0x676414): real semantics on emulator memory, no callee pop
        esp = em.reg('esp'); a_ = em.r32(esp + 4); b_ = em.r32(esp + 8)
        def cs(a):
            b = bytearray()
            while len(b) < 4096:
                x = em.rbytes(a + len(b), 1)[0]
                if x == 0: break
                b.append(x)
            return bytes(b)
        x_, y_ = cs(a_).lower(), cs(b_).lower()
        rv_ = 0 if x_ == y_ else (1 if x_ > y_ else 0xffffffff)
        em.calllog.append(('stricmp', x_, y_, rv_))
        em.ret(eax=rv_, argbytes=0)
    e.w32(0x676414, e.stub_fn('stricmp', _stricmp))
    SYS = newobj(0x1000)
    e.wbytes(SYS, b''.join(_st.pack('<I', r.choice(pool)) for _ in range(0x1000 // 4)))
    e.w32(SYS, vt)
    for off in (0x9b,):
        e.w32(SYS + off, r.choice(pool))
    e.w32(0x70039c, SYS)
    THIS = newobj(0x1000)
    THIS_[0] = THIS
    e.wbytes(THIS, b''.join(_st.pack('<I', val()) for _ in range(0x1000 // 4)))
    e.w32(THIS, vt)
    fb = lambda v: _st.unpack('<I', _st.pack('<f', v))[0]
    for off_ in range(0x400, 0x700, 4):      # UI control pointer arrays / members
        e.w32(THIS + off_, r.choice(pool) if r.random() < 0.93 else 0)
    for off_ in OFFS['unal']:
        if off_ < 0xf20: e.w32(THIS + off_, r.choice(pool))
    for o_ in pool:
        for off_ in range(4, 0x60, 4):
            if r.random() < 0.8: e.w32(o_ + off_, r.choice(pool))
    e.w32(THIS + 4, r.choice(pool))
    # command stream: [this+0xa6] = pointer into random records (types / sizes biased small), [this+0xac] = flag word
    stream = e.alloc(0x400, 4)
    e.wbytes(stream, bytes(r.randrange(0x9f) if r.random() < 0.7 else r.randrange(256) for _ in range(0x400)))
    e.w32(THIS + 0xa6, stream)
    e.w32(THIS + 0xac, r.choice([0, 1, 2, 0x10, 0x0f, 0x8800, 0x2000, r.getrandbits(16), r.getrandbits(32)]))
    e.w32(THIS + 0xa, fb(r.choice([0.0, 0.5, 1.0, r.uniform(0, 10)])))
    e.w32(THIS + 0x54, r.choice([0, 0, r.choice(pool)]))
    e.w32(THIS + 0x8, r.choice([0, 1, 2, 0x100, r.getrandbits(16)]))
    return [THIS]


S(0x5f56f0, 'GUESS lifted 0x5f56f0', 'thiscall', None, ret='eax', gen=g5f56f0, note='batch250500', heap_mask=lambda c: [(0x20202020, 0x800)])
