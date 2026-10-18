"""specs_s250200.py - w3i hand spec for 0x58d000 (batch 234025 lifted port, w3g): universal fake-object graph.
Every vtable slot / direct callee is a generic stub. The callee-pop of each call site comes from the original's call table
(callpops_58d000.json, return address -> pop bytes, from espmap); the PORT run replays the pops the original run recorded (call k pops the
same as call k of the original), so a wrong arity in the port shows up as a stack mismatch instead of being hidden by the stub."""
import json, os, struct as _st
from pilot import S, F
from recruits_util import rnd, clear_hooks, _HOOKED, hook_rec

LOGN = {}
POPS = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callpops_58d000.json'))).items()}
KINDS = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callkinds_58d000.json'))).items()}
SLO, SHI = 0x0fe00000, 0x0ff00000
KINDS[0x58d2c8] = ['bool', [], True]    # s504
KINDS[0x58d2f0] = ['bool', [], True]    # s3f0
KINDS[0x58d6e8] = ['int', [0, 1, 2, 3, 5], False]    # s6a8
KINDS[0x58d6f8] = ['int', [0, 1, 2, 3, 5], False]    # s674
POPS[0x58d082] = 0     # call [eax+0x24c] (ret 0): its two pushed words are popped by the next call 0x6474d0 (ret 8)
GOODS = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'good_58d000.json'))) if os.path.exists(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'good_58d000.json')) else [0]
ST = {'n': 0, 'rec': [], 'k': 0, 'phase': 0}
SLOTS = [0x114, 0x128, 0x12c, 0x130, 0x134, 0x138, 0x1c0, 0x1e0, 0x210, 0x24c, 0x2c4, 0x2d0, 0x2e8, 0x2f0, 0x2f4, 0x2fc, 0x348, 0x384, 0x390, 0x3a8, 0x3dc,
         0x3f0, 0x410, 0x428, 0x438, 0x480, 0x4a8, 0x4c, 0x4f8, 0x504, 0x58, 0x5ec, 0x5f0, 0x650, 0x66c, 0x674, 0x6a8, 0x6e8, 0x80, 0x84, 0x88, 0x8, 0x90, 0x98, 0x0]
REAL = (0x634d7c, 0x4e0870)       # verified pure helpers run as real code
DIRECT = [0x4cc850, 0x43e920, 0x43e960, 0x441940, 0x4419f0, 0x467410, 0x482370, 0x4de480, 0x58ff30, 0x590240, 0x591190, 0x591d80, 0x591e50, 0x592410, 0x593cc0, 0x595250,
          0x595440, 0x595800, 0x596680, 0x596cf0, 0x597720, 0x59c420, 0x59ffc0, 0x5ab070, 0x5cdb70, 0x5d2e60, 0x6474d0]
OFFS = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'offs_58d000.json')))


def g58d000(c):
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
    GB = bytes(r.choice([0, 0, 1, 0xCC, r.randrange(256)]) for _ in range(0x90))
    e.wbytes(0x20201000, GB)
    ST['GB'] = GB
    if not getattr(e, '_w3i_gb_hook', False):
        from unicorn import UC_HOOK_CODE
        e.mu.hook_add(UC_HOOK_CODE, lambda uc, a, sz, u: e.wbytes(e.reg('esp') + 8, ST['GB'][8:0x80]), begin=0x58d01e, end=0x58d01e)   # after the two register saves
        e._w3i_gb_hook = True
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
                mk_ = (name, em.reg('ecx') if name.startswith('s') else em.r32(esp + 4), tuple(KINDS.get(ra, ['unk', [], False])[1]), ra if SITEMEMO else 0, em.r32(esp + 4) if pop >= 4 else 0)
                if ra == 0x58d7db:      # list walk (next node): fresh values, ends with a null after a few steps
                    rv = 0 if r.random() < 0.45 else r.choice(pool)
                elif mk_ in MEMO:
                    rv = MEMO[mk_]       # getters are idempotent: the same slot on the same object returns the same value
                else:
                    rv = MEMO[mk_] = (r.choice(STRS) if name == 's0' else kval(KINDS.get(ra, ['unk', [], False])))
                fills = [[(r.choice(pool) if r.random() < 0.3 else (r.choice([0, 1, 1, 2]) if r.random() < 0.3 else _st.unpack('<I', _st.pack('<f', r.choice([r.uniform(-3, 3), r.uniform(-3, 3), 0.0, 160.0, 210.0, 900.0, 50000.0, 2000000.0, r.uniform(0, 300)])))[0])) for q in range(4)] + [r.choice(pool + [0, 0]), r.getrandbits(1)] for i in range(6)]
                eff = r.random() < 0.3
                st0v = r.choice([0.0, 0.5, 0.95, 1.0, 2.0]) if name == 's1c0' else None
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
            tag_ = ec_ if (name.startswith('s') and name != 's198') else ((('T', ec_ - THIS_[0]) if THIS_[0] <= ec_ < THIS_[0] + 0x1000 else (ec_ if ec_ in pool else 0)) if name.startswith('d') else 0)
            row = [name, tag_] + [em.r32(esp + 4 + 4 * i) for i in range(min(pop // 4, 6))]
            if name == 'd4cc850': row = [name, ec_, em.reg('edx')]     # fastcall(ecx = string, edx = literal)
            if name == 's198':
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
            if name == 's198':       # the cdecl logger formats its message into the caller's buffer (arg 1): deterministic content
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
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'), side=lambda em, k: em.calllog.append(('gs',)))
    for a in DIRECT:
        e.hook(a, stub('d%x' % a)); _HOOKED.add(a)
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
    for off_ in OFFS['unal']:
        if off_ < 0xf20: e.w32(THIS + off_, r.choice(pool))
    for off_ in OFFS['flt']:
        if off_ < 0xf20: e.w32(THIS + off_, fb(r.choice([0.0, 0.25, 0.5, 1.0, 2.0, r.uniform(-3, 3), r.uniform(0, 5)])))
    for o_ in pool:
        e.w32(o_ + 0x23, r.choice(pool))
        e.w32(o_ + 0x817, fb(r.choice([0.0, 0.5, 1.0, 2.5]))); e.w32(o_ + 0x81b, fb(r.choice([0.0, 1.0, 3.0])))     # per-entity float fields read at 0x58dc71 / 0x58dc89
    for off_ in (0x417, 0x832, 0x836, 0x83a, 0x83e, 0x9d3, 0x9d7, 0x9df):       # state / flag words
        e.w32(THIS + off_, r.choice([0, 1, 2, 0x80, 0x81, 0xff, r.getrandbits(32), r.getrandbits(32) & 0x0f0f0f0f, 0x400000, 0x200000, 0x8000000, 0x4000000]))
    o54 = e.alloc(16, 4); e.w32(o54 + 4, r.choice([2, 2, 3])); e.w32(THIS + 0x54, o54)
    for off_ in (0x832, 0x836):
        if r.random() < 0.6: e.w32(THIS + off_, 0)
    for off_ in (0x66b, 0x66c, 0x70, 0x9f4, 0xeed):
        e.wbytes(THIS + off_, bytes([r.choice([0, 1, 1])]))
    e.w32(THIS + 0x93e, r.choice([0, 1, 5, 9, 10, 11, 12]))
    e.w32(THIS + 0x9d3, r.choice([0, 1, 6, 7, 8, 14, 15, 15, 15, 16]))
    e.w32(THIS + 0x9f0, r.choice([0, 0, 1, 3]))
    for off_ in (0x827, 0x829):
        e.wbytes(THIS + off_, bytes([r.choice([0, 1])]))
    e.w32(SYS + 0x40, r.randrange(0, 5000))
    return [THIS]


S(0x58d000, 'GUESS lifted 0x58d000', 'thiscall', None, ret='eax', gen=g58d000, note='batch234025', heap_mask=lambda c: [(0x20202020, 0x800)])
