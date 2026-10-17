"""specs_s250100.py - w3i hand spec for 0x58ecd0 (batch 230012 lifted port): universal fake-object graph.
Every vtable slot / direct callee is a generic stub. The callee-pop of each call site comes from the original's call table
(callpops_58ecd0.json, return address -> pop bytes, from espmap); the PORT run replays the pops the original run recorded (call k pops the
same as call k of the original), so a wrong arity in the port shows up as a stack mismatch instead of being hidden by the stub."""
import json, os, struct as _st
from pilot import S, F
from recruits_util import rnd, clear_hooks, _HOOKED, hook_rec

LOGN = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'logn_58ecd0.json'))).items()}
POPS = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callpops_58ecd0.json'))).items()}
KINDS = {int(k): v for k, v in json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callkinds_58ecd0.json'))).items()}
SLO, SHI = 0x0fe00000, 0x0ff00000
KINDS[0x58ed73] = ['ptr', [1], False]    # s464: sometimes the small value 1 (a count compared with 1 at 0x58f326)
KINDS[0x58ee49] = ['int', [0, 0, 1, 2, 3], False]          # s320 count
KINDS[0x58ee57] = ['int', [0, 1, 2], False]                # s35c
KINDS[0x58eefa] = ['int', [0, 0, 1, 2], False]             # s35c
for _ra in (0x58ef16, 0x58ef4f, 0x58ef67):                  # 5afc70 results compared (unsigned) with the running sum
    KINDS[_ra] = ['int', [2, 3, 4, 6, 9], False]
ST = {'n': 0, 'rec': [], 'k': 0, 'phase': 0}
SLOTS = [0x20, 0x4c, 0x58, 0x7c, 0x80, 0x84, 0x8c, 0x90, 0x98, 0x138, 0x154, 0x190, 0x198, 0x210, 0x2c4, 0x2cc, 0x2d0, 0x2e8, 0x2f0, 0x308, 0x31c,
         0x320, 0x324, 0x328, 0x330, 0x350, 0x35c, 0x360, 0x364, 0x3dc, 0x3f4, 0x464, 0x4f4, 0x504, 0x520, 0x55c, 0x1e0, 0x0]
DIRECT = [0x46abf0, 0x470550, 0x4730b0, 0x48aad0, 0x589c20, 0x591080, 0x591e50, 0x594540, 0x594e30, 0x5966e0, 0x596710, 0x59a580, 0x5aeff0, 0x5af130,
          0x5afc70, 0x5afd00, 0x5afdd0, 0x5afe20, 0x5e93f0]


def g58ecd0(c):
    clear_hooks(c)
    e = c.emu
    r = c.rng
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
    GB = bytes(r.choice([0, 0, 1, 0xCC, r.randrange(256)]) for _ in range(0x3a0))   # per-case garbage for the never-written locals, in the original frame and (copied by the port) in F
    e.wbytes(0x20201000, GB)
    ST['GB'] = GB
    if not getattr(e, '_w3i_gb_hook', False):
        from unicorn import UC_HOOK_CODE
        e.mu.hook_add(UC_HOOK_CODE, lambda uc, a, sz, u: e.wbytes(0xfeffa30 + 12, ST['GB'][12:]) if e.reg('esp') == 0xfeffa30 else None, begin=0x58ecef, end=0x58ecef)   # first instruction after the three register saves: fill the original's locals
        e._w3i_gb_hook = True
    e._heap_next = 0x20202020     # vtable at 0x20202020: a low-page 'object' read at ANY alignment yields the same vtable pointer
    vt = e.alloc(0x600, 4)
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
                mk_ = (name, em.reg('ecx') if name.startswith('s') else em.r32(esp + 4), tuple(KINDS.get(ra, ['unk', [], False])[1]), ra if SITEMEMO else 0)
                if mk_ in MEMO:
                    rv = MEMO[mk_]       # getters are idempotent: the same slot on the same object returns the same value
                else:
                    rv = MEMO[mk_] = (r.choice(STRS) if name == 's0' else kval(KINDS.get(ra, ['unk', [], False])))
                fills = [[(r.choice(pool) if r.random() < 0.3 else (r.choice([0, 1, 1, 2]) if r.random() < 0.3 else _st.unpack('<I', _st.pack('<f', r.uniform(-3, 3)))[0])) for q in range(4)] + [r.choice(pool + [0, 0])] for i in range(6)]
                eff = r.random() < 0.3
                ST['rec'].append((pop, rv, fills, eff))
                ST.setdefault('logn', []).append(LOGN.get(ra, 0))
            else:
                pop, rv, fills, eff = ST['rec'][ST['k']] if ST['k'] < len(ST['rec']) else (0, 0, [[0] * 5] * 6, False)
            ST.setdefault('esp_o' if orig else 'esp_m', []).append(esp)
            if orig: ST.setdefault('ra_o', []).append((hex(ra), name, POPS.get(ra, 0)))
            if not orig: ST.setdefault('ra_esp', {}).setdefault(ra, {}).setdefault(esp, []).append(ST['k'])
            if not orig:
                b_ = bytes(em.rbytes(ra, 6))
                n_ = b_[2] if b_[:2] == b'\x83\xec' else (int.from_bytes(b_[2:6], 'little') if b_[:2] == b'\x81\xec' else None)
                if n_ is not None and n_ != pop:
                    ST.setdefault('popmis', []).append((ST['k'], name, hex(ra), n_, pop))
            ST['k'] += 1
            if os.environ.get('W3I_DBG') and name == 'd59a580': print('59A580', 'orig' if orig else 'port', hex(esp), [hex(em.r32(esp + 4 * i)) for i in range(1, 4)])
            ec_ = em.reg('ecx')
            tag_ = ec_ if (name.startswith('s') and name != 's198') else ((('T', ec_ - THIS_[0]) if THIS_[0] <= ec_ < THIS_[0] + 0x1000 else (ec_ if ec_ in pool else 0)) if name.startswith('d') else 0)
            row = [name, tag_] + [em.r32(esp + 4 + 4 * i) for i in range(min(pop // 4, 6))]
            if name == 's198':
                nl_ = ST['logn'][ST['k'] - 1] if 0 <= ST['k'] - 1 < len(ST['logn']) else 0
                row += [em.r32(esp + 4 + 4 * i) for i in range(nl_)]
            for i in range(min(pop // 4, 6)):
                v = row[2 + i]
                if SLO <= v < SHI:     # stack buffer: log what the function computed, then fill it with the callee's output
                    row[2 + i] = ('S',) + tuple(em.r32(v + 4 * q) for q in range(2))
                    for q in range(4):
                        em.w32(v + 4 * q, fills[i][q])
                    if name == 'd596710':     # the callee fills a 0x48-byte record whose dword at +0x39 (unaligned) is an object pointer
                        for q in range(4, 18):
                            em.w32(v + 4 * q, fills[i][q % 4])
                        em.w32(v + 0x39, fills[i][4])
            em.calllog.append(tuple(row))
            if name == 's0' and orig: rv = ST['rec'][-1][1] if False else rv
            if name == 's198':       # the cdecl logger formats its message into the caller's buffer (arg 1): deterministic content
                bp = em.r32(esp + 8)
                if os.environ.get('W3I_DBG'): print('LOGGER', 'orig' if orig else 'port', hex(esp), [hex(em.r32(esp + 4 * i)) for i in range(1, 6)])
                if SLO <= bp < SHI:
                    em.wbytes(bp, b'log message\0' + bytes(0x30))
            if eff and name in ('d594540', 'd470550', 'd589c20', 'd5afc70', 's2f0'):
                em.w32(THIS_[0] + 0x836, 1)     # the callee sets a state word of the manager
            em.ret(eax=rv, argbytes=pop)
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
        e.w32(o + 4, r.choice([0x6acf44, 0x6acf50, 0x6acf44, 0x6acf50, 0x67c8e8, 0]))   # the name string compared with the exe literals at 0x58f29d / 0x58f4cb / 0x58fd42 / 0x58fe67
    e.w32(0x676410, e.stub_fn('imp676410', stub('i676410')))
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'), side=lambda em, k: em.calllog.append(('gs',)))
    for a in DIRECT:
        e.hook(a, stub('d%x' % a)); _HOOKED.add(a)
    SYS = newobj(0x1000)
    e.wbytes(SYS, b''.join(_st.pack('<I', r.choice(pool)) for _ in range(0x1000 // 4)))
    e.w32(SYS, vt)
    for off in (0x9b,):
        e.w32(SYS + off, r.choice(pool))
    e.w32(0x70039c, SYS)
    UOFF = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'unaligned_offs_58ecd0.json')))
    THIS = newobj(0x1000)
    THIS_[0] = THIS
    e.wbytes(THIS, b''.join(_st.pack('<I', val()) for _ in range(0x1000 // 4)))
    e.w32(THIS, vt)
    for off_ in UOFF:
        if off_ not in (0x832, 0x836) and off_ < 0xf20:
            e.w32(THIS + off_, r.choice(pool))
    for o_ in pool:
        e.w32(o_ + 0x23, r.choice(pool))
    e.w32(THIS + 0x9db, _st.unpack('<I', _st.pack('<f', r.choice([0.0, 0.5, 1.0, 3.0, 100.0])))[0])   # radius limit compared with a vector length at 0x58f6f0
    e.w32(THIS + 0x9d7, r.choice([0, 1])); e.w32(THIS + 0x9df, r.choice([0, 1]))
    A0 = pool[0]
    e.wbytes(THIS + 0x7f2, bytes([r.choice([1] * 9 + [0])]))
    e.w32(THIS + 0x836, r.choice([0] * 9 + [1])); e.w32(THIS + 0x832, r.choice([0] * 9 + [1]))
    return [THIS, A0]


S(0x58ecd0, 'GUESS lifted 0x58ecd0', 'thiscall', None, ret='eax', gen=g58ecd0, note='batch230012')
