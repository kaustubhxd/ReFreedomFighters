"""specs_s750.py - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13."""
from pilot import S, F
from pilot import f32 as _f32


def _flush_heap_code(c):
    """Stub code written into the heap is reused at the same addresses by the next case; drop Unicorn's translations
    for the heap and the exe image so the new bytes run."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _multi_vt(c, slots):
    """Sparse vtable: slots = {byte_offset: (impl, argwords)}; one logged stub per slot, zero words elsewhere."""
    top = max(slots) + 4
    vt = c.emu.alloc(top, 4)
    for off, (impl, aw) in slots.items():
        base = c.emu.logging_vtable('mv%x' % off, 1, impl={0: impl}, argwords={0: aw})
        c.emu.w32(vt + off, c.emu.r32(base))
    return vt


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1000)]


def _out_obj(c):
    return [_rnd(c, 0x1000), _rnd(c, 0x48)]


S(0x4d8c10, 'memberAddr (GUESS)', 'thiscall', None, ret='eax', gen=_obj, note='batch750; lea this+0x84')
S(0x5f0490, 'setVtable (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch750; [this] = 0x6b8284')
def _counter_obj(c):
    o = _rnd(c, 0x1000)
    c.emu.w32(o + 0x300, c.rng.choice([0x10000000, 0x10000000, c.rng.getrandbits(32)]))
    return [o]


S(0x5ab110, 'bumpCounter (GUESS)', 'thiscall', None, ret=None, gen=_counter_obj,
  note='batch750; conditional dword increment at +0x8b7')
S(0x596710, 'copyStateOut (GUESS)', 'thiscall', None, ret=None, gen=_out_obj, note='batch750; copy 0x45 bytes out')


def _float_cfg(c):
    import math
    o = _rnd(c, 0x40)
    x = F(_f32(c.rng.choice([0.0, -0.0, 1.5, -2.25, 1e6, math.nan, math.inf, c.rng.uniform(-100, 100)])))
    return [o, x]


def _ctor_defaults(c):
    import serial_stubs as ss
    ss.patch(c, 0x5edd80, ss.rec(c, 1, ret=0, log=True))   # base ctor stubbed (it faults on random fields)
    return [_rnd(c, 0x100)]


def _callthen_spec(c):
    import serial_stubs as ss
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x14, c.rng.getrandbits(32))
    ss.patch(c, 0x45fa00, ss.rec(c, 1, ret=0, log=True))
    return [o, c.rng.getrandbits(32)]


S(0x524890, 'setFloatConfig (GUESS)', 'thiscall', None, ret=None, gen=_float_cfg,
  note='batch751; float compare with exact-zero semantics')
S(0x43e110, 'callThenClearTwice (GUESS)', 'thiscall', None, ret=None, gen=_callthen_spec,
  note='batch751; calls 0x45fa00, two bit-clear blocks')
S(0x5efd10, 'ctorDefaults (GUESS)', 'thiscall', None, ret='eax', gen=_ctor_defaults,
  note='batch751; calls base ctor 0x5edd80 (this, 3)')


def _clamp_spec(c):
    import math
    o = _rnd(c, 0x40)
    c.emu.wf32(o, c.rng.choice([0.0, -0.0, 1.0, -7.5, 3e4, math.nan, c.rng.uniform(-200, 200)]))
    consts = [c.emu.rf32(x) for x in (0x6ad1fc, 0x6ad234, 0x6ad238, 0x67da18)]   # the exe's own constants
    a = F(_f32(c.rng.choice([0.0, 1.0, -1.0, 5.0, 2.5e3, -2.5e3, math.nan] + consts + [c.rng.uniform(-400, 400)])))
    return [o, a]


def _lookups_spec(c):
    import serial_stubs as ss
    arg = _rnd(c, 0x40)
    c.emu.w32(arg + 4, _rnd(c, 0x40))
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, _rnd(c, 0x40))
    r1 = _rnd(c, 8)
    r2 = _rnd(c, 8)
    c.emu.w32(r1, c.rng.getrandbits(32))
    c.emu.w32(r2, c.rng.getrandbits(32))
    # 5003d0 stand-in (thiscall, one stack word, ret 4): records each stack word in a ring and returns r1 then r2
    cnt = c.emu.alloc(4, 4)
    ring = c.emu.alloc(8, 4)
    c.emu.w32(cnt, 0)
    code = (b'\x8b\x44\x24\x04' + b'\x8b\x15' + ss.P(cnt) + b'\x89\x04\x95' + ss.P(ring)
            + b'\x42' + b'\x89\x15' + ss.P(cnt) + b'\x83\xfa\x01' + b'\xb8' + ss.P(r1) + b'\x74\x05'
            + b'\xb8' + ss.P(r2) + b'\xc2\x04\x00')
    ss.patch(c, 0x5003d0, ss.code(c, code))
    _flush_heap_code(c)
    s0 = c.emu.alloc(4, 4)
    s1 = c.emu.alloc(4, 4)
    sc = c.emu.alloc(4, 4)
    for s_ in (s0, s1, sc):
        c.emu.w32(s_, 0)
    # 59e730 stand-in (thiscall, two stack words, ret 8): stores ecx and both words
    code = (b'\x89\x0d' + ss.P(sc) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(s0)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(s1) + b'\x31\xc0' + b'\xc2\x08\x00')
    ss.patch(c, 0x59e730, ss.code(c, code))
    _flush_heap_code(c)
    return [self_, arg]


S(0x58b6d0, 'clampAccumulate (GUESS)', 'thiscall', None, ret='eax', gen=_clamp_spec,
  note='batch752; float accumulator with a clamp')
S(0x558a50, 'twoLookupsThenCall (GUESS)', 'thiscall', None, ret=None, gen=_lookups_spec,
  note='batch752; two 0x5003d0 lookups, then 0x59e730 (ret 8)')


def _entries_spec(c):
    # contract: 1 <= count and a, b <= count (count 0 makes the original's count - 1 wrap and loop for billions of steps)
    self_ = _rnd(c, 0x200)
    n = c.rng.randint(1, 6)
    c.emu.w32(self_, n)
    a = c.rng.randint(0, n)
    b = a if c.rng.random() < 0.5 else c.rng.randint(0, n)
    return [self_, a, b]


S(0x5a3690, 'removeOrShift (GUESS)', 'thiscall', None, ret=None, gen=_entries_spec,
  note='batch753; remove an entry (a == b) or copy entries down (a != b)')


def _reset_arg_spec(c):
    import serial_stubs as ss
    self_ = _rnd(c, 0x800)
    c.emu.w32(self_ + 0x695, c.rng.choice([0, 0, 1, c.rng.getrandbits(32)]))
    vt = _multi_vt(c, {0x628: (lambda em, x: (0, None), 3), 0x5f4: (lambda em, x: (0, None), 0),
                       0x5f8: (lambda em, x: (0, None), 0)})
    c.emu.w32(self_, vt)
    sc = c.emu.alloc(4, 4)
    s0 = c.emu.alloc(4, 4)
    s1 = c.emu.alloc(4, 4)
    for s_ in (sc, s0, s1):
        c.emu.w32(s_, 0)
    # 478ea0 stand-in (thiscall, two stack words, ret 8): stores ecx and both words, returns 0
    code = (b'\x89\x0d' + ss.P(sc) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(s0)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(s1) + b'\x31\xc0' + b'\xc2\x08\x00')
    ss.patch(c, 0x478ea0, ss.code(c, code))
    _flush_heap_code(c)
    a = _rnd(c, 0x40)
    return [self_, a, c.rng.getrandbits(32)]


S(0x47bf10, 'resetWithArg (GUESS)', 'thiscall', None, ret=None, gen=_reset_arg_spec,
  note='batch754; optional vt 0x628, 478ea0 with ecx = a, vt 0x5f4 and 0x5f8')


def _compact_spec(c):
    import serial_stubs as ss
    self_ = _rnd(c, 0x800)
    n = c.rng.randint(0, 5)
    c.emu.w32(self_ + 0xda, n)
    # two element objects that share a vtable with slot 0x1e0 (returns 0 or 1)
    vt = _multi_vt(c, {0x1e0: (lambda em, x: (c.rng.choice([0, 1]), None), 1)})
    o1 = _rnd(c, 0x40)
    o2 = _rnd(c, 0x40)
    c.emu.w32(o1, vt)
    c.emu.w32(o2, vt)
    for i in range(n):
        c.emu.w32(self_ + 0xde + 4 * i, o1 if c.rng.random() < 0.5 else o2)
    # 513340 stand-in: a predicate returning a 0/1 sequence in eax (its al is what the caller tests)
    ss.patch(c, 0x513340, ss.seqr(c, 1, [c.rng.choice([0, 1]) for _ in range(6)]))
    # render manager object: vt[0x4c] (one stack word)
    rm = _rnd(c, 0x100)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _multi_vt(c, {0x4c: (lambda em, x: (0, None), 1)}))
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    _flush_heap_code(c)
    return [self_]


S(0x513090, 'compactPointers (GUESS)', 'thiscall', None, ret=None, gen=_compact_spec,
  note='batch755; predicate 0x513340, element vt 0x1e0, render vt 0x4c')


def _buf_spec(c):
    import serial_stubs as ss   # noqa: F401
    self_ = _rnd(c, 0x80)
    o8 = _rnd(c, 0x80)
    c.emu.w32(self_ + 8, o8)
    c.emu.w32(o8 + 0x6c, c.rng.choice([0, 0, 1]))
    c.emu.wbytes(self_ + 0x14, bytes([c.rng.choice([0, 1])]))
    # this: vt[0xe0] (four words) and vt[0x20] (none), logged
    e0 = c.rng.getrandbits(32)
    z20 = c.rng.choice([0, 0, 1])
    vt_self = _multi_vt(c, {0xe0: (lambda em, x, v=e0: (v, None), 4), 0x20: (lambda em, x, v=z20: (v, None), 0)})
    c.emu.w32(self_, vt_self)
    # a0: vt[0x84] takes two words and a float pointer; its contents are logged, the pointer is not
    a0 = _rnd(c, 0x40)

    def h84(e, r):
        p = e.arg32(2)
        vals = (e.r32(p), e.r32(p + 4), e.r32(p + 8))
        e.calllog.append(('h84', e.reg('ecx'), e.arg32(0), e.arg32(1), vals))
        e.ret(eax=0, argbytes=12)

    vt_a0 = c.emu.fake_vtable('a0_84', 0x22, {0x84: h84})
    c.emu.w32(a0, vt_a0)
    return [self_, a0, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x43fdd0, 'callWithBuf (GUESS)', 'thiscall', None, ret=None, gen=_buf_spec,
  note='batch756; vt 0xe0, 0x20 on this; a0 vt 0x84 with a stack buffer compared by contents')


def _setup_spec(c):
    import serial_stubs as ss
    self_ = _rnd(c, 0x800)
    c.emu.w32(self_ + 0x60a, c.rng.choice([0, 0, 1, c.rng.getrandbits(32)]))
    vt_self = _multi_vt(c, {0x418: (lambda em, x: (0, None), 0), 0x384: (lambda em, x: (0, None), 2),
                            0x428: (lambda em, x, v=c.rng.getrandbits(32): (v, None), 0),
                            0x368: (lambda em, x: (0, None), 0)})
    c.emu.w32(self_, vt_self)
    r2o = _rnd(c, 0x40)
    c.emu.w32(r2o, _multi_vt(c, {0x94: (lambda em, x: (0, None), 2)}))
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _multi_vt(c, {0x58: (lambda em, x, v=r2o if c.rng.random() < 0.7 else 0: (v, None), 1)}))
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    ss.patch(c, 0x4673d0, ss.rec(c, 0, ret=0, log=True))
    _flush_heap_code(c)
    return [self_]


S(0x484c50, 'firstCallSetup (GUESS)', 'thiscall', None, ret=None, gen=_setup_spec,
  note='batch757; first-call setup, render vt 0x58, tail vt 0x368')


def _range_spec(c):
    self_ = _rnd(c, 0x900)
    n = c.rng.randint(0, 6)
    c.emu.w32(self_ + 0x7ce, n)
    for i in range(n):
        c.emu.w32(self_ + 0x7d2 + 16 * i, c.rng.randint(-6, 6) & 0xffffffff)
    a0 = c.rng.randint(-6, 6) & 0xffffffff
    a1 = c.rng.randint(-6, 6) & 0xffffffff
    return [self_, a0, a1]


S(0x59e690, 'findRangeAndRemove (GUESS)', 'thiscall', None, ret=None, gen=_range_spec,
  note='batch758; first-match scans, then the original 0x5a3690 on the indices')


def _accessor_spec(c):
    import serial_stubs as ss
    arg = _rnd(c, 0x40)
    r1 = _rnd(c, 8)
    r2 = _rnd(c, 8)
    c.emu.w32(r1, c.rng.choice([-1, 0, 1, 3, c.rng.getrandbits(32)]) & 0xffffffff)
    c.emu.w32(r2, c.rng.getrandbits(32))
    c.emu.w32(arg + 4, r1)
    c.emu.w32(arg + 8, r2)
    # 5003d0 stand-in (one stack word, ret 4): records each stack word in a ring and returns r1 then r2
    cnt = c.emu.alloc(4, 4)
    ring = c.emu.alloc(8, 4)
    c.emu.w32(cnt, 0)
    code = (b'\x8b\x44\x24\x04' + b'\x8b\x15' + ss.P(cnt) + b'\x89\x04\x95' + ss.P(ring)
            + b'\x42' + b'\x89\x15' + ss.P(cnt) + b'\x83\xfa\x01' + b'\xb8' + ss.P(r1) + b'\x74\x05'
            + b'\xb8' + ss.P(r2) + b'\xc2\x04\x00')
    ss.patch(c, 0x5003d0, ss.code(c, code))
    # 5002f0 stand-in (one stack word, ret 4): stores ecx and its word
    sc = c.emu.alloc(4, 4)
    sa = c.emu.alloc(4, 4)
    c.emu.w32(sc, 0)
    c.emu.w32(sa, 0)
    ss.patch(c, 0x5002f0, ss.code(c, b'\x89\x0d' + ss.P(sc) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(sa) + b'\xc2\x04\x00'))
    ss.patch(c, 0x5057e0, ss.rec(c, 2, ret=0, log=True))
    obj = _rnd(c, 0x80)
    c.emu.w32(obj + 0x44, c.rng.getrandbits(32))
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    self_ = _rnd(c, 0x80)
    vt = _multi_vt(c, {0x50: (lambda em, x, v=c.rng.getrandbits(32): (v, None), 6)})
    c.emu.w32(self_, vt)
    _flush_heap_code(c)
    return [self_, arg]


S(0x505490, 'setFromAccessor (GUESS)', 'thiscall', None, ret=None, gen=_accessor_spec,
  note='batch759; 5003d0 twice, render vt 0x50 (six words), 5057e0 (ret 8), 5002f0 (ret 4)')


def _bucket_spec(c):
    import serial_stubs as ss
    _rnd(c, 0x40)   # padding: v can be negative, so A[v] reaches below the object
    self_ = _rnd(c, 0x900)
    for i in range(8):
        c.emu.w32(self_ + 4 + 4 * i, c.rng.getrandbits(32))
    keys = sorted(c.rng.randint(-6, 6) for _ in range(8))
    for i, k in enumerate(keys):
        c.emu.w32(self_ + 0x804 + 4 * i, k & 0xffffffff)
        c.emu.w32(self_ + 0x800 + 4 * i, c.rng.randint(-6, 6) & 0xffffffff)
    c.emu.w32(self_ + 0x820, c.rng.randint(0, 7))
    for k in range(8):
        c.emu.w32(self_ + 0x81c - 4 * k, c.rng.choice([0, 1, 2, 3, 7]))
    # keep v at or below the largest key: the first stage scans K upward and would run past the table otherwise
    v = c.rng.randint(-2, keys[7]) & 0xffffffff
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0, log=True))   # the no-match hook: a recording stub (non-null)
    _flush_heap_code(c)
    return [self_, v]


S(0x4a1710, 'bucketUpdate (GUESS)', 'thiscall', None, ret=None, gen=_bucket_spec,
  note='batch760; bucket update, hook at 0x7003b0 set to a recording stub')


def _node_spec(c):
    import serial_stubs as ss
    # the string and the length it asks for
    s = _rnd(c, 16)
    c.emu.wbytes(s, bytes(c.rng.choice(b'ab') for _ in range(c.rng.randint(0, 5))) + b'\x00')
    slen = 0
    while c.emu.rbytes(s + slen, 1)[0] != 0:
        slen += 1
    b = c.rng.choice([0, slen + 1, slen + 2, 3])
    # nodes: length field (b or other) and data
    nodes = []
    seq = []
    for _ in range(c.rng.randint(0, 4)):
        n = _rnd(c, 0x20)
        ln = c.rng.choice([b if b else slen + 1, 5])
        c.emu.w32(n, ln & 0xffffffff)
        nodes.append(n)
        seq.append((n, c.rng.choice([0, 1])))
    seq.append((0, 0))
    state = {'i': 0}
    # embedded object at this+0x4008: vt[0x4c] writes 1 through its pointer; vt[0x5c] returns the next node and writes its flag
    def h4c(em, args):
        em.w32(args[0], 1)
        return (0, None)

    def h5c(em, args):
        i = min(state['i'], len(seq) - 1)
        state['i'] += 1
        node, fl = seq[i]
        em.w32(args[0], fl)
        return (node, None)

    vt_obj = c.emu.logging_vtable('nodeobj', 0x30, impl={0x4c: h4c, 0x5c: h5c}, argwords={0x4c: 1, 0x5c: 1})
    self_ = _rnd(c, 0x4100)
    c.emu.w32(self_ + 0x4008, vt_obj)
    # import 0x67640c: a cdecl stand-in that records its three words and returns 0 or 1
    ret = c.rng.choice([0, 1])
    sl = [c.emu.alloc(4, 4) for _ in range(3)]
    for x in sl:
        c.emu.w32(x, 0)
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(sl[0]) + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(sl[1])
            + b'\x8b\x44\x24\x0c' + b'\xa3' + ss.P(sl[2]) + b'\xb8' + ss.P(ret) + b'\xc3')
    c.emu.w32(0x67640c, ss.code(c, code))
    _flush_heap_code(c)
    return [self_, s, b]


S(0x4d2a90, 'findNodeByLen (GUESS)', 'thiscall', None, ret='al', gen=_node_spec, stack_arg_bytes=4,
  note='batch761; bool; embedded object vt 0x4c/0x5c with stack out-param; import 0x67640c stand-in')


def _chain_save_spec(c):
    import math
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 4, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x48, c.rng.getrandbits(32))
    c.emu.wf32(self_ + 0x64, c.rng.choice([0.0, 1.5, -2.25, 1e6, math.nan, c.rng.uniform(-100, 100)]))
    c.emu.wbytes(self_ + 0x84, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))
    c.emu.w32(self_ + 0xf0, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0xdc, c.rng.getrandbits(32))
    a = _rnd(c, 0x40)
    save = _rnd(c, 0x40)
    # the chain of objects: a->vt[0x4c] returns objB; objB->vt[0x60] returns objC; objC->vt[0x60] returns 0
    objC = _rnd(c, 0x40)
    c.emu.w32(objC, _multi_vt(c, {0x60: (lambda em, x: (0, None), 1)}))
    objB = _rnd(c, 0x40)
    c.emu.w32(objB, _multi_vt(c, {0x60: (lambda em, x, v=objC: (v, None), 1)}))
    c.emu.w32(a, _multi_vt(c, {0x4c: (lambda em, x, v=objB: (v, None), 1)}))
    r44 = c.rng.getrandbits(32)
    vt_s = _multi_vt(c, {0x3c: (lambda em, x, v=a: (v, None), 1), 0x44: (lambda em, x, v=r44: (v, None), 1)})
    c.emu.w32(save, vt_s)
    _flush_heap_code(c)
    return [self_, save]


S(0x563490, 'saveChain (GUESS)', 'thiscall', None, ret='al', gen=_chain_save_spec,
  note='batch762; residue 17 big; save vt 0x3c/0x44, object vt 0x4c (float) and 0x60 (bytes)')


def _log_dispatch_spec(c):
    import serial_stubs as ss
    arg = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    c.emu.wbytes(p, bytes([c.rng.getrandbits(8)]))
    c.emu.wbytes(p + 4, bytes([c.rng.choice([0, 1, 2, 5, 0xff])]))
    c.emu.w32(arg + 4, p)
    sc = c.emu.alloc(4, 4)
    sr = c.emu.alloc(4, 4)
    c.emu.w32(sc, 0)
    c.emu.w32(sr, 0)
    ss.patch(c, 0x5003d0, ss.code(c, b'\x89\x0d' + ss.P(sc) + b'\xb8' + ss.P(p) + b'\xc2\x04\x00'))
    # the log object: vt[0x20] returns an object o whose vt[0x2c] takes three words (logged)
    o = _rnd(c, 0x40)
    def h2c(em, r):
        em.calllog.append(('mv2c', em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0)   # caller-cleaned (cdecl-style): the asm site pops the three words
    vt2c = c.emu.fake_vtable('o2c', 0x30, {0x2c: h2c})
    c.emu.w32(o, vt2c)
    lg = _rnd(c, 0x40)
    c.emu.w32(lg, _multi_vt(c, {0x20: (lambda em, x, v=o: (v, None), 2)}))
    c.emu.w32(0x700390, lg)
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0, log=True))
    # this: vt at this+0x1c with slot 0x6d8 (two words, logged)
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _multi_vt(c, {0x6d8: (lambda em, x: (0, None), 2)}))
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, obj)
    _flush_heap_code(c)
    return [self_, arg]


S(0x5590d0, 'logThenDispatch (GUESS)', 'thiscall', None, ret=None, gen=_log_dispatch_spec,
  note='batch763; residue 17 big; log vt 0x20/0x2c, hook 0x7003b0, vt 0x6d8')


def _vt_store_spec(c):
    import serial_stubs as ss
    arg = _rnd(c, 0x40)
    p = _rnd(c, 0x40)
    c.emu.w32(arg + 8, _rnd(c, 0x40))
    # 5003d0 stand-in (one stack word, ret 4): records ecx and its word, returns p
    sc = c.emu.alloc(4, 4)
    sa = c.emu.alloc(4, 4)
    c.emu.w32(sc, 0)
    c.emu.w32(sa, 0)
    ss.patch(c, 0x5003d0, ss.code(c, b'\x89\x0d' + ss.P(sc) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(sa) + b'\xb8' + ss.P(p) + b'\xc2\x04\x00'))
    # 5002f0 stand-in (one stack word, ret 4): stores ecx and its word
    tc = c.emu.alloc(4, 4)
    ta = c.emu.alloc(4, 4)
    c.emu.w32(tc, 0)
    c.emu.w32(ta, 0)
    ss.patch(c, 0x5002f0, ss.code(c, b'\x89\x0d' + ss.P(tc) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(ta) + b'\xc2\x04\x00'))
    # this+0x14 object: vt[0x358] returns a random word (no stack words)
    rv = c.rng.getrandbits(32)
    rv2 = (rv ^ 0x5a5a5a5a) & 0xffffffff
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, _multi_vt(c, {0x358: (lambda em, x, v=rv: (v, None), 0), 0x35c: (lambda em, x, v=rv2: (v, None), 0)}))
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x14, obj)
    _flush_heap_code(c)
    return [self_, arg]


S(0x519610, 'setFromVtResult (GUESS)', 'thiscall', None, ret=None, gen=_vt_store_spec,
  note='batch764; residue 17 big; vt 0x358 (no words), 5003d0 (ret 4), 5002f0 (ret 4)')


def _vt_arg_spec(c):
    import serial_stubs as ss
    arg = c.rng.getrandbits(32)
    # vt[0x0c] on the object: three stack words, caller-cleaned (logged, argbytes 0)
    def h0c(em, r):
        em.calllog.append(('mv0c', em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0)
    o = _rnd(c, 0x40)
    vt0c = c.emu.fake_vtable('o0c', 0x30, {0x0c: h0c})
    c.emu.w32(o, vt0c)
    c.emu.w32(0x724270, o)   # the global the getter returns
    _flush_heap_code(c)
    return [arg]


S(0x5fa4d0, 'vtCallArg (GUESS)', 'stdcall', None, ret=None, gen=_vt_arg_spec,
  note='batch765; residue 17 big; getter 0x5fa630 reads [0x724270]; vt 0x0c, three words, caller-cleaned')
