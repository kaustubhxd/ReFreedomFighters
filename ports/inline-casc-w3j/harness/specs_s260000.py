"""specs_s260000.py - Sonnet-w3j spec for 0x5f56f0 Process_t::runProcess (script VM main loop), port batch260000 (lift2.py).
A real Process_t image (VM data stack = vector {data,cap,size} at +0x34 of 8-byte entries, variable block at *(this+0x9e), pc at +0xa6, flags word +0xac,
step budget u16 at +8) and an opcode stream built from decoders/opcodes.md (operand kinds). Verified exe callees run as REAL code on both sides; only the
vtable calls (this slots, this[4] chain, objects) are Python stubs seeded per case, so the original and the port run draw the same values."""
import os, re, struct as st
from pilot import S
from recruits_util import clear_hooks, obj, pystub, logger, stub_memmove

HERE = os.path.dirname(os.path.abspath(__file__))
OPS = {}
for _l in open(os.path.join(HERE, '..', '..', '..', 'decoders', 'opcodes.md')):
    _m = re.match(r'\| (\d+) \| 0x([0-9a-f]+) \| (\S+) \| (.*?) \| (\d+) \| (.*?) \| (\w+) \|', _l)
    if _m: OPS[int(_m.group(1))] = (_m.group(3), [x.strip() for x in _m.group(4).split(',')] if _m.group(4) != '—' else [], int(_m.group(5)))

SIMPLE = [o for o, (n, ops, ln) in OPS.items() if all(k in ('u16 var', 'u16 var dst', 'u16 var src', 'f32', 'i32') for k in ops + ([] if o not in (105, 113, 115, 124) else [])) or o in (105, 113, 115, 104, 126, 151)]
XOPS = set(range(30, 38)) | {44, 45} | set(range(64, 74)) | {96, 97, 98, 99}
def xtype(o):
    n = OPS[o][0]
    if o in (128, 152): return 'o'
    return 'f' if (n.endswith('_F') or n.endswith('F_IMM')) else 'i'
def vartype(o):
    n = OPS[o][0]
    if o in (127, 129): return 'o'
    if n in ('LOAD_F2I', 'STORE_I2F'): return 'f' if n == 'STORE_I2F' else 'f'
    if n in ('LOAD_I2F', 'STORE_F2I'): return 'i'
    return 'f' if ('_F' in n or n.endswith('F')) else 'i'
def _sig(o):
    """(popped kinds top-first, pushed kinds bottom-first); kinds 'i' int (tag 1), 'f' float (tag 2), '*' any. None: not generated yet."""
    n = OPS[o][0]
    if o in (0, 1, 2, 22, 23, 24, 25, 26, 27, 28, 29, 40, 41, 100, 101, 102, 103) or 136 <= o <= 143: return ([], [])
    if o == 3: return (['*'], ['i'])
    if o == 127: return (['o'], [])
    if o == 129: return ([], ['o'])
    if o == 128: return ([], [])
    if o in (152, 153, 154): return ([], ['o'])
    if o in (4, 5, 9, 10): return (['i', 'i'], ['i'])
    if o in (6, 7): return (['f', 'f'], ['i'])
    if o in (8, 11): return (['i'], ['i'])
    if o in (12, 13, 134): return (['f'], ['f'])
    if 14 <= o <= 21: return ((['f', 'f'], ['f']) if n.endswith('_F') else (['i', 'i'], ['i']))
    if o in (38, 39): return (['f', 'f'], ['f'])
    if o in (42, 46, 49): return ([], ['f'])
    if o in (43, 47, 48, 135, 148): return ([], ['i'])
    if 50 <= o <= 63: return ([('f' if (n.endswith('_F') or n.endswith('F2I')) else 'i')], [])
    if 84 <= o <= 89: return (['i', 'i'], ['i'])
    if 90 <= o <= 95: return (['f', 'f'], ['i'])
    if o == 106: return (['**', '**'], 'swap')
    if o in (104, 113, 115, 151): return ([], [])
    if o == 105: return (['i'], ['f'])
    if o == 126: return ([], ['i'])
    if 30 <= o <= 37 or 64 <= o <= 73 or 96 <= o <= 99: return ([], [])
    if o == 44: return ([], ['i'])
    if o == 45: return ([], ['f'])
    return None
def _eff(o):
    g = _sig(o)
    return None if g is None else (len(g[0]), 0)
SIMPLE = [o for o in SIMPLE if _eff(o)]
FORCE = [int(x, 0) for x in os.environ.get('W3J_OPS', '').split(',') if x]
FLOATS = [0.0, 1.0, -1.0, 0.5, 2.0, 3.0, 100.0, -7.25, 1e10, 0.3]
POPS = {0x0: 2, 0x4: 1, 0x14: 1, 0x18: 2, 0x30: 1}
NSLOT = 0x40
NSTR = 6
POPPS = {'p': POPS, 'o': {0x30: 1, 0x14: 1, 0x18: 2}, 'e': {0: 2}}


CF = float(os.environ.get('W3J_CF', '0.3'))
CFSET = [x for x in os.environ.get('W3J_CFSET', '').split(',') if x]
TERMS = ['strop', 'waitev', 'sleepwait', 'quota0', 'hjf', 'setfn', 'arefbad', 'term', 'bad']


def gen(c):
    clear_hooks(c)
    e = c.emu; r = c.rng
    SR = [0]

    def mk(name, off, ret):
        def h(em, res_):
            esp = em.reg('esp'); ecx = em.reg('ecx'); pop = POPPS.get(name, {}).get(off, 0)
            args = tuple(em.r32(esp + 4 + 4 * i) for i in range(pop))
            if name == 'o' and off == 0x14 and args:      # call descriptor on the caller's stack: log its words, the two slice structs {vector, start, count} by content, and the embedded-object pointer relative to this
                d = args[0]; w = [em.r32(d + 4 * k) for k in range(5)]
                def sl(p_):
                    return tuple(em.r32(p_ + 4 * k) for k in range(3)) if 0xf000000 <= p_ < 0x10000000 else p_
                args = (w[0], sl(w[1]), sl(w[2]), w[3], w[4] & 0xffff)
            em.calllog.append((name, off, ecx - THIS if THIS <= ecx < THIS + 0x1000 else 0, args))
            SR[0] += 1
            v = ret(SR[0])
            if name == 'q':
                em.ret(eax=0, argbytes=4 * pop, st0=v)
            else:
                em.ret(eax=v, argbytes=4 * pop)
        return e.stub_fn('%s_%x' % (name, off), h)
    THIS = e.alloc(0xd00, 4)
    logger(c)
    OBJS = []
    stub_memmove(c)
    def lgh(em, res_):      # cdecl formatter slot 0x14 of the engine object: 5 args from 0x5f9260 (ret 0x5f9293), 4 from the default-opcode site 0x5f8a77
        esp = em.reg('esp'); ra = em.r32(esp); n = 5 if ra == 0x5f9293 else (6 if em.r32(esp + 12) == 0x6b8fe8 else 4)
        av = []
        for i in range(n):
            v = em.r32(esp + 4 + 4 * i)
            av.append('S' if 0xf000000 <= v < 0x10000000 else v)
        em.calllog.append(('lg', n, tuple(av)))
        em.ret(eax=0, argbytes=0)
    def tmh(em, res_):
        em.calllog.append(('time',)); em.ret(eax=0, argbytes=0, st0=r.choice([0.0, 1.5, 100.0]))
    GSTR = []
    for t_ in (b'Entity01\0', b'wait\0', b'x\0'):
        a_ = e.alloc(len(t_), 1); e.wbytes(a_, t_); GSTR.append(a_)
    def lg2(em, res_):      # slot 0xc: cdecl printf-like formatter: the argument words are counted from the format string (%f / %e / %g = 2 words, other specs 1)
        esp = em.reg('esp'); fmt = em.r32(esp + 8)
        fs = cstr(em, fmt); n = 1
        i = 0
        while i < len(fs):
            if fs[i:i + 1] == b'%':
                if fs[i + 1:i + 2] == b'%': i += 2; continue
                j = i + 1
                while j < len(fs) and fs[j:j + 1] in b'-+ #0123456789.lhI': j += 1
                n += 2 if fs[j:j + 1] in b'feEgG' else 1
                i = j
            i += 1
        em.calllog.append(('lg2', fs[:20], tuple(em.r32(esp + 4 + 4 * k) if k != 1 else 0 for k in range(n + 1))))
        em.ret(eax=0, argbytes=0)
    def g1c(em, res_):      # slot 0x1c, pops 1: returns a name string
        esp = em.reg('esp'); a0 = em.r32(esp + 4)
        em.calllog.append(('g1c', a0))
        em.ret(eax=r.choice(GSTR), argbytes=4)
    e.w32(0x724270, obj(c, 0x40, {0x14: e.stub_fn('lg', lgh), 0x4: e.stub_fn('time', tmh), 0xc: e.stub_fn('lg2', lg2), 0x1c: e.stub_fn('g1c', g1c)}))
    def cstr(em, a):
        out = b''
        while len(out) < 64:
            ch = bytes(em.rbytes(a, 1))
            if ch == b'\0': break
            out += ch; a += 1
        return out
    def sic(em, res_):
        esp = em.reg('esp'); a, b = cstr(em, em.r32(esp + 4)), cstr(em, em.r32(esp + 8))
        em.calllog.append(('_stricmp', a, b))
        x, y = a.lower(), b.lower()
        em.ret(eax=0 if x == y else (1 if x > y else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', sic))
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=0))))

    def vt(name, retf=lambda k: (k * 0x9e3779b1) & 0xffffffff):
        v = e.alloc(NSLOT * 4 + 4, 4)
        for off in range(0, NSLOT, 4):
            e.w32(v + off, mk(name, off, retf))
        return v
    LATE = [r.random() < 0.25, 0]
    def late_enqueue(k):
        if LATE[0] and not LATE[1] and e.r32(THIS + 0x54) == 0:
            LATE[1] = 1
            _qo = e.alloc(0x20, 4); e.w32(_qo, VTQ[0]); qa = e.r32(THIS + 0x4c); e.w32(qa, _qo); e.w32(THIS + 0x54, 1)
        return (k * 0x9e3779b1) & 0xffffffff
    VTQ = [0]
    vtp = e.alloc(NSLOT * 4 + 4, 4)
    for off in range(0, NSLOT, 4):
        e.w32(vtp + off, mk('p', off, (lambda k: r.choice(OBJS)) if off == 0 else ((lambda k: late_enqueue(k)) if off == 0x28 else (lambda k: (k * 0x9e3779b1) & 0xffffffff))))
    e.w32(THIS, vtp)
    vto = e.alloc(NSLOT * 4 + 4, 4)
    for off in range(0, NSLOT, 4):
        e.w32(vto + off, mk('o', off, (lambda k: r.choice(OBJS)) if off == 0x24 else (lambda k: (k * 0x9e3779b1) & 0xffffffff)))
    for _ in range(4):
        _o = e.alloc(0x20, 4); e.w32(_o, vto); OBJS.append(_o)
    vte = e.alloc(NSLOT * 4 + 4, 4)
    for off in range(0, NSLOT, 4):
        e.w32(vte + off, mk('e', off, (lambda k: OBJS[0]) if off == 0 else (lambda k: (k * 0x9e3779b1) & 0xffffffff)))
    e.w32(THIS + 0xaca, vte)
    A = e.alloc(0x40, 4); e.w32(A + 0x18, e.alloc(0x40, 4)); e.w32(A + 0x1c, 8); e.w32(A + 0x20, 0)     # registry vector (0x5fbb00 appends the new process)
    e.w32(THIS + 0x58, e.alloc(0x40, 4)); e.w32(THIS + 0x5c, 8); e.w32(THIS + 0x60, 0)               # this's own child vector
    def malloc(em, res_):
        sz = em.arg32(0); em.calllog.append(('malloc', sz)); blk = em.alloc(sz, 16)
        if sz == 0xad2: em.w32(blk + 0xb6, blk + 0xbe)       # a fresh Process_t: the record ring pointer must point at its ring (0x5f3c90 dereferences it)
        em.ret(eax=blk, argbytes=0)
    e.stub_import('malloc', malloc)
    A_ = A; Bq = e.alloc(0x40, 4); Q = e.alloc(0x40, 4)
    e.w32(THIS + 4, A); e.w32(A + 0x24, Q); e.w32(Q, vt('q', lambda k: r.choice([0.0, 1.0, 5.0, 50.0])))
    e.w32(A, vt('a'))
    budget = r.choice([2, 3, 5, 8, 12, 20])
    e.w16(THIS + 8, budget)
    e.wf32(THIS + 0xa, r.choice([0.0, 0.5, 1.0, 100.0]))
    flags = r.choice([1, 2, 3, 5, 1, 2, 6, 7, 8]) | (0x1000 if r.random() < 0.12 else 0)
    e.w16(THIS + 0xac, flags)
    # VM data stack
    cap = 64
    data = e.alloc(8 * cap, 4)
    L = r.choice([0, 2, 3, 4])
    TG = [1, 2, 1, 2, 4]
    LT = [r.choice(TG) for _ in range(L)]
    n0t = r.choice([0, 1, 2, 3, 4, 6, 8])
    if FORCE: n0t = 12
    n0 = L + n0t
    KI = LT + [r.choice(TG) for _ in range(n0t)]
    if n0t >= 2 and r.random() < 0.3: KI[-1] = KI[-2] = 2
    kinds = [{1: 'i', 2: 'f', 4: 'o'}[k] for k in KI[L:]]
    G = 4
    GT = [r.choice(TG) for _ in range(G)]
    gdata = e.alloc(8 * G + 8, 4)
    for i in range(G):
        e.w32(gdata + 8 * i, r.choice(OBJS) if GT[i] == 4 else r.choice([r.getrandbits(32) | 1, 1, 7, st.unpack('<I', st.pack('<f', r.choice(FLOATS[1:])))[0]])); e.w8(gdata + 8 * i + 4, GT[i])
    e.w32(THIS + 0x28, gdata); e.w32(THIS + 0x30, G); e.w16(THIS + 0xaa, L)
    for i in range(n0):
        kind = KI[i]
        e.w32(data + 8 * i, r.choice(OBJS) if kind == 4 else r.choice([r.getrandbits(32), 0, 1, 3, st.unpack('<I', st.pack('<f', r.choice(FLOATS)))[0]]))
        e.w8(data + 8 * i + 4, kind)
    e.w32(THIS + 0x34, data); e.w32(THIS + 0x38, cap); e.w32(THIS + 0x3c, n0)
    # variable block, pc, program
    var = e.alloc(0x90, 4)
    for i in range(0x20):
        e.w32(var + 4 * i, r.choice([r.getrandbits(32) | 1, 1, 2, 7] + [st.unpack('<I', st.pack('<f', r.choice(FLOATS[1:])))[0]] * 5))
    for _k in range(4): e.w32(var + 0x40 + 4 * _k, r.choice(OBJS))
    e.w32(THIS + 0x9e, var)
    # pending-object queue (drained by 0x5f4ac0 at the prologue / exit): objects with id 0 (slot 0x5c), a name (0x54), nonzero 0x40, release 0x28
    vtq = e.alloc(0x80, 4)
    for off in range(0, 0x80, 4):
        e.w32(vtq + off, mk('qo', off, (lambda k: 0) if off == 0x5c else ((lambda k: r.choice(GSTR)) if off == 0x54 else ((lambda k: 1) if off == 0x40 else (lambda k: (k * 0x9e3779b1) & 0xffffffff)))))
    VTQ[0] = vtq
    nq = r.choice([0, 0, 0, 1, 1, 2])
    qarr = e.alloc(0x40, 4)
    for i_ in range(nq):
        _qo = e.alloc(0x20, 4); e.w32(_qo, vtq); e.w32(qarr + 4 * i_, _qo)
    e.w32(THIS + 0x4c, qarr); e.w32(THIS + 0x54, nq); e.w32(THIS + 0x8c, 0)
    code = bytearray(b'\x7b')    # offset 0 = YIELD: the not-found handler lookup (assert hook returns 0) jumps to offset 0 and ends the run
    ST['ops'] = []
    def pickvar(t, direct_only=False):
        x = (r.random() * (0.5 if TAGB[0] else 1.0)) if not NOLOC[0] else 0.4
        tg = {'i': 1, 'f': 2, 'o': 4}[t]
        loc = [i for i in range(L) if LT[i] == tg]
        glo = [i for i in range(G) if GT[i] == tg]
        if not direct_only and x < 0.3 and loc and not NOLOC[0]: return (-(L - r.choice(loc))) & 0xffff
        if not direct_only and x < 0.5 and glo: return 0xbfff - r.choice(glo)
        if t == 'o': return 0x40 + 4 * r.randrange(4)
        return 4 * r.randrange(0, 16)
    def pushi(v): code.append(43); code.extend(st.pack('<i', v))
    def pushf(v): code.append(42); code.extend(st.pack('<f', v))
    def emit_operands(o):
        nm, ops, ln = OPS[o]
        if o == 128:
            pushi(pickvar('o')); code.append(129); code.extend(st.pack('<H', pickvar('o')))
        elif o == 152:
            pushi(pickvar('o'))
        if o in XOPS:
            t = xtype(o)
            if o in (64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 98, 99):
                pushi(pickvar(t))
                if t == 'i': pushi(r.choice(([1, 1, 2, -3, 7] if o == 70 else [1, 2, -3, 7, 0, 5])))
                else: pushf(r.choice([x_ for x_ in FLOATS if x_ != 0.0] if o == 71 else FLOATS))
            else: pushi(pickvar(t))
        code.append(o)
        for k in ops:
            if k == 'u16 var src' and o == 139: code.extend(st.pack('<H', 4 * r.randrange(0x18, 0x1e)))
            elif k.startswith('u16 var'): code.extend(st.pack('<H', pickvar(vartype(o), direct_only=(o == 139))))
            elif k == 'f32': code.extend(st.pack('<f', r.choice(FLOATS + [0.0, 0.0, 0.0])))
            elif k == 'u16 str': code.extend(st.pack('<H', r.randrange(0, NSTR)))
            elif k == 'u32 unused': code.extend(bytes(4))
            elif k == 'u32 n': code.extend(st.pack('<I', r.randrange(0, 3)))
            elif k in ('u32 imm', 'u32 state'): code.extend(st.pack('<I', r.choice([0, 1, 5, 0x20, 0x1234])))
            else: code.extend(st.pack('<i', r.choice([1, 2, -1, 5, 100, 0x40] + ([] if o in (29, 36) else [0]))))
    NEUT = [o for o in SIMPLE if _sig(o) == ([], []) and o not in XOPS and o not in (1, 2) or o in (1, 2)]
    NEUT = [o for o in NEUT if _sig(o) == ([], [])]
    def neutral(n, noloc=False):
        NOLOC[0] = noloc
        for _ in range(n):
            o = r.choice(NEUT)
            if o in (21, 61): continue
            emit_operands(o)
        NOLOC[0] = False
    def patch(pos, v): code[pos:pos + 4] = st.pack('<I', v)
    def u32(v=0): code.extend(st.pack('<I', v))
    SUBS = []
    TAGB = [False]
    NOLOC = [False]
    STT = []
    FNT = {}
    NF = 6
    FNT[4] = 7; FNT[5] = 0x1234
    LOCKOK = [not (flags & 0x1000)]     # EVLOCK locks only while flag 0x1000 is clear (initial 0x1000 makes it assert; the first EVUNLOCK clears it)
    CTOR = r.random() < 0.08
    if CTOR: code.extend(b'\x77\x7b')     # CTOR_END at the start (call stack empty) then YIELD; this[0x12] = start state
    HM = (not CTOR) and r.random() < 0.10        # handler-jump mode: [YIELD] HANDLER_JMP(_FN) with a key that EXISTS in the map, then a visible marker on the not-jumped path
    O70 = (not CTOR and not HM) and r.random() < 0.06     # op 0x70 mode: string operand, visible marker, YIELD
    FOCUS = (not CTOR and not HM and not O70) and r.random() < 0.6     # one op repeated with fresh operands (no gadgets): raises the per-op frequency
    FOL = sorted(set(SIMPLE) | XOPS | {128, 152, 153, 154})
    FO = FOL[(c.case * 7 + 3) % len(FOL)]      # deterministic sweep over every op: each op gets its share of the focus cases
    TAGB[0] = FOCUS and (((c.case * 7 + 3) // len(FOL)) % 2 == 0)      # successive visits of the same op alternate tagged / direct operands deterministically     # tagged (local / global) variable operands whenever a matching entry exists
    SWM = (not CTOR and not HM and not O70 and not FOCUS) and r.random() < 0.08          # switch mode: observable match / default / fall-through paths (distinct markers)
    SVM = (not CTOR and not HM and not O70 and not FOCUS and not SWM) and r.random() < 0.08   # JMP_SETSV then JSV1 / JNSV1 (the compare constant of d[node+0x40] with 1)
    def marker(var, val): code.append(101); code.extend(st.pack('<H', var)); code.extend(st.pack('<i', val))
    if SWM:
        fl = r.random() < 0.35; n = r.randrange(1, 4)
        vals = [r.choice([0, 1, 2, 5]) for _ in range(n)]
        if fl: pushf(r.choice([0.0, 0.5, 1.0, 3.0, 6.0]))
        else: pushi(r.choice(vals + [9, 0, 1]))
        code.append(108 if fl else 107); u32(n); u32(0xffffffff if r.random() < 0.5 else 0)
        tps = []
        for v_ in vals:
            if fl: code.extend(st.pack('<f', float(v_)))
            else: u32(v_)
            tps.append(len(code)); u32()
        marker(0x84, 0x66); code.append(123)               # fall-through (default -1 / no match)
        Lm = len(code); marker(0x8c, 0x55); code.append(123)   # matched target
        for tp in tps: patch(tp, Lm)
    if SVM:
        code.append(114); pj = len(code); u32(); code.extend(st.pack('<i', r.choice([-1, 0, 1, 2, 1, 2])))
        L1 = len(code); patch(pj, L1)
        code.append(r.choice([116, 117])); pj2 = len(code); u32()
        marker(0x8c, 0x11); L2 = len(code); patch(pj2, L2)
        marker(0x84, 0x22); code.append(123)
    LKC = (not CTOR and not HM and not O70 and not FOCUS and not SWM and not SVM and LOCKOK[0]) and r.random() < 0.06      # locked CALL_METHOD with a late-enqueued queue object (the lock bit test after the call)
    if LKC:
        LATE[0] = True
        if r.random() < 0.4:      # TERMINATE under the lock: the flag bit goes to this[0xb4] instead of this[0xac]
            code.append(155); code.append(122); marker(0x8c, 0x98); code.append(123)
        else:
            code.append(155); code.append(150); code.extend(st.pack('<H', pickvar('o'))); code.extend(st.pack('<H', r.randrange(0, NSTR))); code.extend(st.pack('<H', 0)); code.extend(st.pack('<I', r.choice([0, 0x20000])))
            code.append(156); marker(0x8c, 0x99); code.append(123)
    STM = (not CTOR and not HM and not O70 and not FOCUS and not SWM and not SVM and not LKC) and r.random() < 0.06     # state-change mode: SETSTATE / SETSTATE_V / SETSTATE_FN at the start (unlocked: stacks cleared), marker at the state target
    if STM:
        v_ = r.choice([81, 82, 83])
        if v_ == 81: code.append(81); u32(len(code) + 4)
        elif v_ == 82: code.append(82); u32(0x7c); STT.append(len(code))
        else: code.append(83); code.extend(st.pack('<H', 0)); FNT[0] = len(code)
        marker(0x8c, 0xaa); code.append(123)
    DVM = (not CTOR and not HM and not O70 and not FOCUS and not SWM and not SVM and not LKC and not STM) and r.random() < 0.06      # default-value mode: type-name strings through 0x82 (int / float / object)
    if DVM:
        for _d in range(r.randrange(2, 6)):
            code.append(130); code.extend(r.choice([b'int', b'float', b'INT', b'Float', b'Entity01', b'float']) + b'\0')
    CASTM = (not CTOR and not HM and not O70 and not FOCUS and not SWM and not SVM and not LKC and not DVM and not STM) and r.random() < 0.06     # cast mode: typed top + every type name through 0x85
    if CASTM:
        for _c in range(r.randrange(2, 6)):
            if r.random() < 0.5:
                pushi(r.choice([0, 1, 5])); code.append(133); code.extend(r.choice([b'Fuzzy', b'Float', b'Bool', b'stateref', b'bool', b'fuzzy']) + b'\0')
            else:
                pushf(r.choice([0.0, 1.0, 2.5])); code.append(133); code.extend(r.choice([b'Int', b'Bool', b'Fuzzy', b'SceneRef', b'ActorRef', b'SoundRef', b'SoundSetRef']) + b'\0')
    if HM:
        if r.random() < 0.5:
            code.append(120); u32(r.choice([7, 0x1234])); code.extend(st.pack('<i', r.choice([-1, 0, 1, 2])))
        else:
            code.append(121); code.extend(st.pack('<H', r.choice([4, 5]))); code.extend(st.pack('<i', r.choice([-1, 0, 1])))
        code.append(101); code.extend(st.pack('<H', 0x8c)); code.extend(st.pack('<i', 0x77))     # marker: only runs when the handler was NOT found / not jumped
    if O70:
        code.append(112); code.extend(bytes(r.choice(b'abcdefghijkl') for _ in range(r.randrange(1, 12))) + b'\0')
        code.append(101); code.extend(st.pack('<H', 0x8c)); code.extend(st.pack('<i', 0x66)); code.append(123)
    for _kk in range(budget + 2):
        if CTOR or HM or O70 or CASTM or SWM or SVM or LKC or DVM or STM: break
        if _kk >= int(os.environ.get('W3J_K', '999')): break
        if (not FOCUS) and r.random() < CF and len(kinds) < cap - 12:
            g = r.choice(CFSET or (TERMS if r.random() < 0.04 else ['jnz', 'jz', 'jmp', 'jzy', 'call', 'popn', 'jsv', 'jsv', 'jmpsv', 'frame', 'quota', 'budget', 'evlock', 'callm', 'callm', 'switch', 'switch', 'sleep', 'sleepi', 'hjmp', 'aref', 'callfn', 'defval', 'cast', 'cast', 'calln', 'calln', 'castobj', 'dump', 'dump', 'lockg', 'lockg', 'lnotbad', 'lorf', 'cmpf', 'divvvz', 'lockst', 'castz', 'op7c', 'divf0', 'castempty'] + (['state'] if r.random() < 0.15 else []) + (['term'] if r.random() < 0.1 else []) + (['bad'] if r.random() < 0.1 else []) + (['waitev'] if r.random() < 0.07 else []) + (['arefbad', 'hjf', 'setfn', 'quota0', 'sleepwait'] if r.random() < 0.2 else []) + (['strop'] if r.random() < 0.07 else [])))
            if g == 'jmp':
                code.append(77); pos = len(code); u32(); neutral(r.randrange(1, 3)); patch(pos, len(code))
            elif g in ('jnz', 'jz'):
                pushi(r.choice([0, 1, 2, -1])); pf = r.choice([0, 1])
                code.append(78 if g == 'jnz' else 79); pos = len(code); u32(); u32(pf)
                neutral(r.randrange(1, 3)); patch(pos, len(code))
                if not pf: kinds.append('i')
            elif g == 'jzy':
                pushi(r.choice([0, 1, 1])); code.append(80); pos = len(code); u32(); patch(pos, len(code))
            elif g == 'call':      # JMP over an inline subroutine (neutral ops + RET), then CALLA into it
                code.append(77); pj = len(code); u32()
                sub = len(code); neutral(r.randrange(0, 3)); code.append(75)
                patch(pj, len(code))
                code.append(118); u32(sub)
            elif g == 'jsv':
                code.append(r.choice([116, 117])); pos = len(code); u32(); neutral(r.randrange(1, 3)); patch(pos, len(code))
            elif g == 'jmpsv':
                code.append(114); pos = len(code); u32(); code.extend(st.pack('<i', r.choice([-1, 0, 1, 2]))); neutral(r.randrange(1, 3)); patch(pos, len(code))
            elif g == 'sleep':
                lk = r.random() < 0.3 and len(kinds) < cap - 14 and LOCKOK[0]
                if lk: code.append(155)
                pushf(r.choice([0.0, 0.5, 2.0])); pushi(r.choice([0, 0, 1]))
                code.append(109)
                if lk: code.append(156)
            elif g == 'sleepi':
                code.append(110); u32(r.choice([0, 0, 1])); code.extend(st.pack('<f', r.choice([0.0, 0.5, 2.0])))
            elif g == 'hjmp':
                code.append(120); u32(r.choice([0, 7, 0x1234, 7])); code.extend(st.pack('<i', r.choice([-1, 0, 1, 2])))
            elif g == 'aref':
                pushi(r.randrange(0, 8)); code.append(125); u32(r.choice([4, 8])); u32(0x100); u32(0x80)
            elif g == 'arefbad':
                pushi(r.choice([-1, 8, 99])); code.append(125); u32(4); u32(0x100); u32(0x80); code.append(123); break
            elif g == 'hjf':
                code.append(121); code.extend(st.pack('<H', r.choice([0, 1, 4, 5, 5]))); code.extend(st.pack('<i', r.choice([-1, 0, 1]))); code.append(123); break
            elif g == 'setfn':
                k = r.randrange(0, 4); code.append(83); code.extend(st.pack('<H', k)); FNT[k] = len(code); break
            elif g == 'callfn':
                code.append(77); pj = len(code); u32()
                sub = len(code); neutral(r.randrange(0, 3)); code.append(75)
                patch(pj, len(code))
                k = r.randrange(0, 4); FNT[k] = sub
                code.append(74); code.extend(st.pack('<H', k))
            elif g in ('lockg', 'lockst') and not LOCKOK[0]:
                code.append(155); code.append(156); LOCKOK[0] = True     # initial flag 0x1000: EVLOCK would assert and not lock; EVUNLOCK clears 0x1000 first
            elif g == 'lockg':
                v = r.choice(['sleepi', 'waitev', 'str70', 'term', 'callm'])
                code.append(155)
                if v == 'sleepi': code.append(110); u32(r.choice([0, 1])); code.extend(st.pack('<f', r.choice([0.0, 2.0])))
                elif v == 'callm':
                    code.append(150); code.extend(st.pack('<H', pickvar('o'))); code.extend(st.pack('<H', r.randrange(0, NSTR))); code.extend(st.pack('<H', 0)); code.extend(st.pack('<I', r.choice([0, 0x20000])))
                elif v == 'waitev': code.append(111)
                elif v == 'str70': code.append(112); code.extend(b'ab\0')
                else: code.append(122); break
                code.append(156)
                if v == 'str70': code.append(123); break
            elif g == 'castempty':      # CALL_METHOD with one result slot leaves an EMPTY (tag 0) entry on top; the cast then takes the unknown-kind assert path; POPN removes the entry
                code.append(150); code.extend(st.pack('<H', pickvar('o'))); code.extend(st.pack('<H', r.randrange(0, NSTR))); code.extend(st.pack('<H', 0)); code.extend(st.pack('<I', 1 | r.choice([0, 0x20000])))
                code.append(133); code.extend(r.choice([b'Int', b'Float', b'zzz']) + b'\0'); code.append(76); u32(1)
            elif g == 'castz':
                if r.random() < 0.5: pushi(r.choice([0, 1, 5]))
                else: pushf(r.choice([0.0, 1.0, 2.5]))
                code.append(133); code.extend(r.choice([b'zzz', b'Widget']) + b'\0'); code.append(76); u32(1)
            elif g == 'divf0':     # DIV_F (0x14) with a zero divisor: report, then the division continues (inf / nan result, pc advances)
                pushf(r.choice([0.0, 1.0, 2.0])); pushf(0.0); code.append(20); kinds.append('f')
            elif g == 'op7c':
                code.append(124); u32(0)
            elif g == 'lnotbad':
                code.append(129); code.extend(st.pack('<H', pickvar('o'))); code.append(3)
            elif g == 'lorf':
                pushf(r.choice([0.0, 1.0])); pushf(r.choice([0.0, 1.0])); code.append(r.choice([6, 7])); kinds.append('i')
            elif g == 'cmpf':
                pushf(r.choice([0.0, 1.0, 2.0])); pushf(r.choice([0.0, 1.0, 2.0])); code.append(r.choice(range(90, 96))); kinds.append('i')
            elif g == 'divvvz':
                code.append(101); code.extend(st.pack('<H', 0x64)); code.extend(st.pack('<i', 0))
                code.append(139); code.extend(st.pack('<H', 4 * r.randrange(0, 16))); code.extend(st.pack('<H', 0x64))
            elif g == 'lockst':
                code.append(155)
                v = r.choice([81, 82, 83])
                if v == 81: code.append(81); u32(len(code) + 4)
                elif v == 82: code.append(82); u32(0x7c); STT.append(len(code))
                else: code.append(83); code.extend(st.pack('<H', 0)); FNT[0] = len(code)
                code.append(156)
            elif g == 'divf0':
                pushf(0.0); code.append(60); code.extend(st.pack('<H', 4 * r.randrange(0, 16)))
            elif g == 'dump':
                code.append(145)
            elif g == 'calln':
                static = r.random() < 0.5
                nrecv = 0 if static else 1
                B = r.randrange(0, min(3, len(kinds)) + 1)
                if not static:
                    code.append(129); code.extend(st.pack('<H', pickvar('o'))); kinds.append('o')
                code.append(149); code.extend(st.pack('<H', r.randrange(0, NSTR))); code.extend(st.pack('<H', r.randrange(0, NSTR)))
                A = r.choice([0, 0, 1]); code.extend(st.pack('<H', r.choice([0, 1, 7]))); code.extend(st.pack('<I', (B << 8) | A | (0x20000 if static else 0)))
                if A: code.append(76); u32(A)
                n = B + nrecv
                if n: del kinds[len(kinds) - n:]
            elif g == 'castobj':
                code.append(129); code.extend(st.pack('<H', pickvar('o'))); kinds.append('o')
                code.append(133); code.extend(r.choice([b'ActorRef', b'zzz', b'Entity01']) + b'\0'); kinds.pop()
            elif g == 'defval':
                nm = r.choice([b'int', b'float', b'Entity01', b'INT', b'Float'])
                code.append(130); code.extend(nm + b'\0')
                kinds.append('i' if nm.lower() == b'int' else ('f' if nm.lower() == b'float' else 'o'))
            elif g == 'cast' and kinds and kinds[-1] in ('i', 'f'):
                if kinds[-1] == 'i':
                    nm = r.choice([b'Fuzzy', b'Float', b'Bool', b'stateref', b'bool']); kinds[-1] = 'f' if nm.lower() in (b'fuzzy', b'float') else 'i'
                else:
                    nm = r.choice([b'Int', b'Bool', b'Fuzzy', b'SceneRef', b'ActorRef', b'SoundRef', b'SoundSetRef', b'int']); kinds[-1] = 'i' if nm.lower() in (b'int', b'bool') else 'f'
                code.append(133); code.extend(nm + b'\0')
            elif g == 'quota0':
                pushi(r.choice([0, -1])); code.append(146); code.append(123); break
            elif g == 'sleepwait':
                pushf(0.0); pushi(0); code.append(109); code.append(111); code.append(123); break
            elif g == 'waitev':
                code.append(111); code.append(123); break
            elif g == 'strop':
                code.append(112); code.extend(r.choice([b'a\0', b'Entity01\0', b'abcdefghij\0'])); code.append(123); break
            elif g == 'switch':
                fl = r.random() < 0.4
                n = r.randrange(1 if fl else 0, 4)
                vals = [r.choice([0, 1, 2, 5]) for _ in range(n)]
                if fl: pushf(r.choice([0.0, 0.5, 1.0, 3.0, 6.0]))
                else: pushi(r.choice([0, 1, 2, 5, 9]))
                code.append(108 if fl else 107); u32(n); dpos = len(code); u32(0xffffffff if r.random() < 0.3 else 0)
                tps = [dpos] if code[dpos:dpos + 4] != b'\xff\xff\xff\xff' else []
                for v in vals:
                    if fl: code.extend(st.pack('<f', float(v)))
                    else: u32(v)
                    tps.append(len(code)); u32()
                neutral(r.randrange(0, 3))
                for tp in tps:
                    if tp == dpos and code[dpos:dpos + 4] == b'\x00\x00\x00\x00' and r.random() < 0.5: continue     # default target 0 = YIELD at offset 0
                    patch(tp, len(code))
            elif g == 'callm':
                B = r.randrange(0, min(3, len(kinds)) + 1)
                code.append(150); code.extend(st.pack('<H', pickvar('o'))); code.extend(st.pack('<H', r.randrange(0, NSTR)))
                A = r.choice([0, 0, 1]); code.extend(st.pack('<H', r.choice([0, 1, 7]))); code.extend(st.pack('<I', (B << 8) | A | r.choice([0, 0x20000])))
                if A: code.append(76); u32(A)
                if B: del kinds[len(kinds) - B:]
            elif g == 'evlock':
                code.append(155); neutral(r.randrange(0, 3)); code.append(156); LOCKOK[0] = True
            elif g == 'bad':
                code.append(r.choice([0x83, 0x84, 0xa0, 0xff])); break
            elif g == 'term':
                code.append(r.choice([122, 123, 158])); break
            elif g == 'frame' and kinds:     # LEAVE needs n >= 1: FRAME -0 == FRAME 0 is another ENTER (it would leave the frame pointer moved for good)
                n = r.randrange(1, min(3, len(kinds)) + 1)
                code.append(144); code.extend(st.pack('<i', 0)); neutral(r.randrange(0, 3), noloc=True)
                code.append(144); code.extend(st.pack('<i', -n))
                del kinds[len(kinds) - n:]
            elif g == 'quota':
                pushi(r.choice([1, 3, 20])); code.append(146)
            elif g == 'budget':
                code.append(147); u32(r.choice([2, 5, 30]))
            elif g == 'dump':
                code.append(145)
            elif g == 'state':
                if r.random() < 0.5: code.append(81); u32(len(code) + 4)
                else: code.append(82); u32(0x7c); STT.append(len(code))
                break
            elif g == 'popn':
                n = r.randrange(0, min(3, len(kinds)) + 1) if kinds else 0
                if n or True:
                    code.append(76); u32(n)
                    if n: del kinds[len(kinds) - n:]
            continue
        def room(o):
            g = _sig(o)
            return len(kinds) + len(g[0]) + (len(g[1]) if g[1] != 'swap' else 0) < cap - 6
        def okk(o):
            g = _sig(o)
            kk = kinds + ['i'] if o in (21, 61) else kinds
            if len(kk) < len(g[0]) or len(kk) + (len(g[1]) if g[1] != 'swap' else 0) - len(g[0]) >= cap - 3: return False
            return all(k == '**' or (k == '*' and kk[-1 - i] in ('i', 'f')) or kk[-1 - i] == k for i, k in enumerate(g[0]))
        cand = [o for o in (FORCE or SIMPLE) if room(o)]
        if FOCUS and room(FO): cand = [FO]
        o = r.choice(cand); ST.setdefault('ops', []).append(o); nm, ops, ln = OPS[o]
        g = _sig(o)
        fresh = bool(g[0]) and (not okk(o) or r.random() < 0.4 or o == 60)
        if fresh:      # push fresh typed operands so that every typed op is exercised equally often (top-first kinds in g[0])
            if o == 21:
                pushi(r.choice([0, 1, 2, 5, -3, 7])); pushi(r.choice([1, 2, -3, 7])); kinds.extend(['i', 'i'])
            elif o == 61:
                pushi(r.choice([1, 1, 2, -3, 7])); kinds.append('i')
            else:
                for k in reversed(g[0]):
                    if k == 'f': pushf(r.choice([x_ for x_ in FLOATS if x_ != 0.0] if o == 60 else FLOATS)); kinds.append('f')
                    elif k == 'o': code.append(129); code.extend(st.pack('<H', pickvar('o'))); kinds.append('o')
                    elif k == '**' and r.random() < 0.5: code.append(129); code.extend(st.pack('<H', pickvar('o'))); kinds.append('o')
                    else: pushi(r.choice([0, 1, 2, 5, -3, 7])); kinds.append('i')
        elif o in (21, 61): kinds.append('i')
        if g[1] == 'swap': kinds[-1], kinds[-2] = kinds[-2], kinds[-1]
        else:
            del kinds[len(kinds) - len(g[0]):]; kinds.extend(g[1])
        if o in (21, 61) and not fresh:     # integer divisors must be nonzero (the original faults on idiv by zero after its error report)
            code.append(43); code.extend(st.pack('<i', r.choice([1, 2, -3, 7])))
        emit_operands(o)
    END_Y = len(code); code.append(101); code.extend(st.pack('<H', 0x88)); code.extend(st.pack('<i', 0x55)); code.append(123)     # SETV_I var 0x88 = 0x55 (visible marker) then the final YIELD: target of the handler-map entries
    code += bytes(16)
    pc = e.alloc(len(code) + 16, 4); e.wbytes(pc, bytes(code))
    e.w32(THIS + 0xa6, pc + 1)
    for _t in STT: e.w32(var + 0x7c, _t)
    nd = e.alloc(0x200, 4)
    e.w32(nd + 0x48, 0); e.w32(nd + 0x54, pc); e.w32(nd + 0x58, pc + len(code) + 16); e.w32(nd + 0x9c, 0)
    if CTOR: e.w32(THIS + 0x12, r.choice([0xffffffff, 1, 0, 0xffffffff]))
    e.w32(THIS + 0xb6, THIS + 0xbe); e.w32(THIS + 0xba, 4); e.w32(THIS + 0x6c, 0xffffffff); e.w32(THIS + 0x68, 0xffffffff); e.w32(THIS + 0x64, r.choice([0, 7, 0x20]))
    strs = []
    for t_ in (b'a\0', b'Entity01\0', b'methodX\0', b'0123456789abcdef\0', b'z\0', b'\0'):
        a_ = e.alloc(len(t_), 1); e.wbytes(a_, t_); strs.append(a_)
    arr = e.alloc(4 * NSTR, 4)
    for i_, a_ in enumerate(strs): e.w32(arr + 4 * i_, a_)
    e.w32(nd + 0xa0, 0); e.w32(nd + 0xa8, NSTR); e.w32(nd + 0xac, arr); e.w32(nd + 0xb0, 0)
    evid = r.choice([0, 3, 0x40]); e.w16(THIS + 0x1e, evid)
    head = e.alloc(0x40, 4); e.w32(nd + 0x121, head)      # std::map head (sentinel) at the UNALIGNED field node+0x121: [head+1] = root
    if HM or r.random() < 0.85:                           # outer map: key 7 (root), key 0x1234 (right child); each value = inner map keyed by the u16 event id
        N1 = e.alloc(0x20, 4); N2 = e.alloc(0x20, 4)
        e.w32(head + 1, N1)
        for Nn, key in ((N1, 7), (N2, 0x1234)):
            e.w32(Nn + 5, 0); e.w32(Nn + 9, 0); e.w32(Nn + 0xd, key)
            M = e.alloc(0x10, 4); hI = e.alloc(0x40, 4); rI = e.alloc(0x20, 4)
            e.w32(M, hI); e.w32(hI + 1, rI); e.w32(rI + 5, 0); e.w32(rI + 9, 0)
            e.w16(rI + 0xd, evid if (HM or r.random() < 0.7) else (evid + 1) & 0xffff); e.w32(rI + 0xf, END_Y)
            e.w32(Nn + 0x11, M)
        e.w32(N1 + 9, N2)
    farr = e.alloc(4 * NF, 4)
    for k_ in range(NF): e.w32(farr + 4 * k_, FNT.get(k_, 0))
    e.w32(nd + 0x104, NF); e.w32(nd + 0x108, farr)
    e.w32(var + 0x80, 8)
    e.w32(nd + 0x3c, 0x84); e.w32(nd + 0x40, 0x78); e.w32(THIS + 0x96, nd)
    cs = e.alloc(8 * 48, 4); e.w32(THIS + 0x40, cs); e.w32(THIS + 0x44, 48); e.w32(THIS + 0x48, 0)
    ST['var'] = var; ST['data'] = data; ST['gdata'] = gdata; ST['pcbuf'] = pc; ST['code'] = bytes(code); ST['L'] = L; ST['n0'] = n0; ST['budget'] = budget; ST['this'] = THIS; ST['pc0'] = pc + 1; ST['lens'] = [OPS[b][2] for b in ST.get('ops', [])]
    return [THIS]


ST = {}
def ring_mask(c):      # record ring at this+0xbe (4 x 0x14 bytes) filled by 0x5f3c90 from the drain's stack struct: bytes +0xe..+0x13 of each record are UNINITIALISED stack garbage of 0x5f4ac0 (different stack contents on the two sides)
    t = c.args[0]
    return [(t + 0xbe + 0x14 * k + 0xe, 6) for k in range(4)]


S(0x5f56f0, 'runProcess lifted2', 'thiscall', None, ret='eax', gen=gen, note='batch260000', max_insns=400000, heap_mask=ring_mask)
