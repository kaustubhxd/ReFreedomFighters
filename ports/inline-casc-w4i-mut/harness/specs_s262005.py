"""specs_s262005.py - w4i spec for 0x4b4990: universal fake-object graph (technique of w3i, specs_s250400.py)."""
import json, os, struct as _st
from pilot import S, F
from recruits_util import rnd, clear_hooks, _HOOKED, hook_rec

_D = os.path.dirname(os.path.abspath(__file__))
LOGN = {int(k): v for k, v in json.load(open(os.path.join(_D, 'logn_4b4990.json'))).items()}
POPS = {int(k): v for k, v in json.load(open(os.path.join(_D, 'callpops_4b4990.json'))).items()}
KINDS = {int(k): v for k, v in json.load(open(os.path.join(_D, 'callkinds_4b4990.json'))).items()}
SLO, SHI = 0x0fe00000, 0x0ff00000
GOODS = json.load(open(os.path.join(_D, 'good_4b4990.json'))) if os.path.exists(os.path.join(_D, 'good_4b4990.json')) else list(range(777000, 779000))
FIXPOP = {0x4b4cb9: 4}     # slot 0x4c(ebx) at 0x4b4cb6: the earlier push belongs to the following call 0x4b7f90
ST = {'n': 0, 'rec': [], 'k': 0, 'phase': 0}
SLOTS = [0x4, 0x20, 0x2c, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x64, 0x80, 0x84, 0xbc, 0x100, 0x114, 0x130, 0x138, 0x1ac, 0x1b8, 0x1c8, 0x1d8, 0x1e0, 0x22c, 0x234, 0x274, 0x2e4, 0x2f8, 0x4b4, 0x4d0, 0x500, 0x504, 0x584, 0x0]
DIRECT = [0x4dc110, 0x4b5500, 0x4db9a0, 0x4b48c0, 0x4db860, 0x4b7f90, 0x4db6c0, 0x4de480, 0x4a5da0, 0x4dbe30, 0x4dbb00, 0x4dc630, 0x4cc1d0, 0x4cbec0, 0x4dbd10, 0x4da340]
LITS = [0x68fde8, 0x68ff3c, 0x691b10, 0x691edc, 0x69212c, 0x692140, 0x692158, 0x692178, 0x692188, 0x6921a8, 0x692204, 0x692238, 0x692288, 0x67c8e8]


def g4b4990(c):
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
    PN = r.choice([0.02, 0.08, 0.15, 0.3])     # per-case null probability of pointer returns
    DEEP = r.random() < 0.5          # deep mode: steer the gates of the main flow (names match in list 3, lists 1 / 2 end at once, flag words favourable)
    NAMEEQ = 1.0 if DEEP else r.choice([0.3, 0.7, 1.0])
    NULLP = r.choice([0.05, 0.15, 0.3])
    PZ = r.choice([0.2, 0.4, 0.6])           # per-case zero probability of unknown / arg returns
    try:
        e.mu.mem_map(0, 0x10000)    # small integers used as pointers read zeros (same on both sides)
    except Exception:
        pass

    def newobj(n=0x900):
        o = e.alloc(n, 4)
        pool.append(o)
        return o
    ST['GB'] = b''
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
                pop = FIXPOP.get(ra, POPS.get(ra, 0))
                if name.startswith('s') and os.environ.get('W3I_DYNPOP', '1') == '1' and pop > 0 and ra not in FIXPOP:
                    pop = max(0, (em.reg('ebp') - 0x230 - esp) - 4)     # outstanding pushes at an indirect call (ebp frame, 0x78 locals + 3 saved registers): the callee consumes them all
                    ST.setdefault('dyn', {}).setdefault(hex(ra), set()).add(pop)
                mk_ = (name, em.reg('ecx') if name.startswith('s') else em.r32(esp + 4), tuple(KINDS.get(ra, ['unk', [], False])[1]), ra if SITEMEMO else 0, em.r32(esp + 4) if pop >= 4 else 0)
                if name == 'd4dc110':           # c_str of a name object: one of the literals / test strings
                    rv = ST['a0'] if r.random() < (0.06 if ra in (0x4b4a34, 0x4b4aa4) else NAMEEQ) else r.choice(STRS)    # loops 1 / 2 exit on a match: keep it rare there
                elif DEEP and name == 's54' and r.random() < 0.9:     # object lookup by id: a real object in deep mode
                    rv = r.choice(pool)
                elif name in ('s64', 's5c'):      # list walk (next element): fresh values, ends with a null after a few steps
                    rv = 0 if r.random() < (0.85 if (DEEP and ra in (0x4b49fe, 0x4b4a51, 0x4b4a77, 0x4b4ac1)) else NULLP) else r.choice(pool)
                elif mk_ in MEMO:
                    rv = MEMO[mk_]       # getters are idempotent: the same slot on the same object returns the same value
                else:
                    rv = MEMO[mk_] = (r.choice(STRS) if name == 's0' else kval(KINDS.get(ra, ['unk', [], False])))
                fills = [[(r.choice(pool) if r.random() < 0.3 else (r.choice([0, 1, 1, 2, 3, 4]) if r.random() < 0.3 else _st.unpack('<I', _st.pack('<f', r.choice([r.uniform(-3, 3), r.uniform(-3, 3), 0.0, 160.0, 210.0, 900.0, 50000.0, 2000000.0, r.uniform(0, 300)])))[0])) for q in range(4)] + [r.choice(pool + [0, 0]), r.getrandbits(1)] for i in range(6)]
                eff = r.random() < 0.3
                if name == 's5c': fills[0][0] = 0 if rv == 0 else 1      # iterator valid flag (first dword of the iterator buffer) ends the loop with the null element
                st0v = r.choice([0.0, 0.5, 0.95, 1.0, 2.0]) if name == 's1c0' else None
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
            ST['k'] += 1
            ec_ = em.reg('ecx')
            tag_ = (('S' if SLO <= ec_ < SHI else ec_) if (name.startswith('s') and name != 's2c') else ((('T', ec_ - THIS_[0]) if THIS_[0] <= ec_ < THIS_[0] + 0x1000 else (ec_ if ec_ in pool else 0)) if name.startswith('d') else 0))
            row = [name, tag_] + [em.r32(esp + 4 + 4 * i) for i in range(min(pop // 4, 6))]
            if name == 's2c':
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
            if name.startswith('d') and True:      # register arguments (fastcall / thiscall) that point into the caller's stack are output buffers: log and fill them
                for j_, rg_ in enumerate(('ecx', 'edx')):
                    if rg_ == 'edx' and name not in ('d43e920', 'd43e960', 'd441940', 'd4419f0', 'd4de480'): continue
                    v_ = em.reg(rg_)
                    if SLO <= v_ < SHI:
                        row.append((rg_, 'S') + tuple(em.r32(v_ + 4 * q) for q in range(2)))
                        for q in range(3): em.w32(v_ + 4 * q, fills[4 + j_][q])
            em.calllog.append(tuple(row))
            if name == 's0' and orig: rv = ST['rec'][-1][1] if False else rv
            em.ret(eax=rv, argbytes=pop, st0=st0v)
        return h
    e.mu.mem_write(0, _st.pack('<I', vt) * (0x10000 // 4))
    e.w32(0x3c, 0x00040000)       # flags word of a null-ish object (field +0x3c): distinguishes `je` / fall-through on a null object pointer
    e.w32(0x50, 0)
   # a small integer used as an object pointer reads vtable-valued words
    STRS = []
    def mkc(t_):
        a_ = e.alloc(len(t_) + 1, 4); e.wbytes(a_, t_ + b'\0'); return a_
    lit_strs = []
    for la in LITS:
        raw = bytes(e.rbytes(la, 64)); t_ = raw.split(b'\0')[0]
        lit_strs.append(la); STRS.append(la)
    for t_ in (b'a', b'0123456789abcdef', b'Entity01', b''):
        STRS.append(mkc(t_))
    for la in (0x692140, 0x692158, 0x692178, 0x692188):      # strings that agree with a literal in the first two characters but differ later (inline 2-char-step compares)
        t_ = bytes(e.rbytes(la, 64)).split(b'\0')[0]
        for v_ in (t_[:-1] + b'#', t_ + b'x', t_[:2] + b'~', t_[:1] + b'#' + t_[2:]):
            STRS.append(mkc(v_))
    for off in SLOTS:
        e.w32(vt + off, e.stub_fn('s%x' % off, stub('s%x' % off)))
    for o in pool:
        words = [(r.choice(pool) if (DEEP and r.random() < 0.7) else val()) for _ in range(0x900 // 4)]
        e.wbytes(o, b''.join(_st.pack('<I', w) for w in words))
        e.w32(o, vt)
        e.w32(o + 4, 0 if r.random() < 0.12 else r.choice(STRS))
        f_ = e.r32(o + 0x3c) & ~(0x400 | 0x40040000)
        f_ |= (0x400 if (DEEP or r.random() < 0.7) else 0) | r.choice([0, 0, 0x40000000, 0x40040000, 0x00040000])
        e.w32(o + 0x3c, f_)
        e.w32(o + 0x23, r.choice([0x900000, 0x900000, 0x80000d, 0x100000, 0x800000]) if (DEEP and r.random() < 0.8) else r.choice([0, 0x100000, 0x800000, 0x900000, 0x200002, 0x80000d, 0x80000d, r.getrandbits(32) & 0xffff0000]))
        if r.random() < 0.85: e.w32(o + 0xc, r.choice(pool))
    e.hook(0x633654, lambda em, res_=None: (em.calllog.append(('gs',)), em.ret(argbytes=0)))     # /GS check: preserves eax like the real routine
    _HOOKED.add(0x633654)
    for a in DIRECT:
        e.hook(a, stub('d%x' % a)); _HOOKED.add(a)
    def _strcmp(em, res_=None):       # cdecl strcmp-style import (IAT 0x676414), no callee pop
        esp = em.reg('esp'); a_ = em.r32(esp + 4); b2 = em.r32(esp + 8)
        def cs(a):
            bb = bytearray()
            while len(bb) < 4096:
                x = em.rbytes(a + len(bb), 1)[0]
                if x == 0: break
                bb.append(x)
            return bytes(bb)
        x_, y_ = cs(a_), cs(b2)
        rv_ = 0 if x_ == y_ else (1 if x_ > y_ else 0xffffffff)
        em.calllog.append(('strcmp', x_, y_, rv_))
        em.ret(eax=rv_, argbytes=0)
    e.w32(0x676414, e.stub_fn('strcmp', _strcmp))
    SYS = newobj(0x2000)
    e.wbytes(SYS, b''.join(_st.pack('<I', r.choice(pool)) for _ in range(0x2000 // 4)))
    e.w32(SYS, vt)
    e.w32(SYS + 0x9b, r.choice(pool))
    e.w32(0x70039c, SYS)
    THIS = newobj(0x1000)
    THIS_[0] = THIS
    e.wbytes(THIS, b''.join(_st.pack('<I', val()) for _ in range(0x1000 // 4)))
    e.w32(THIS, vt)
    e.w32(THIS + 0xf2, vt)       # embedded list objects (unaligned)
    e.w32(THIS + 0x10e, vt)
    ST['a0'] = r.choice(STRS)
    e.wbytes(SYS + 0x68, bytes([0 if DEEP else r.choice([0] * 8 + [1])]))
    e.wbytes(THIS + 0x4c, bytes([0 if DEEP else r.choice([0] * 8 + [1])]))
    return [THIS, ST['a0'], val(), val()]


S(0x4b4990, 'GUESS lifted 0x4b4990', 'thiscall', None, ret='eax', gen=g4b4990, note='batch262005', heap_mask=lambda c: [(0x20202020, 0x800)])
