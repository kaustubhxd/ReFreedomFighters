"""specs_s200.py - unclaimed area 20 (docs/20-unclaimed-20.md): leaf thiscall getters and a field copy, plain ret."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x1400)]


def _global(c):
    c.emu.w32(0x724270, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return []


S(0x4681f0, 'getDword1d6 (unnamed)', 'thiscall', None, ret='eax', gen=_obj, note='batch200; reads dword at +0x1d6')
S(0x483ef0, 'getBit1 (unnamed)', 'thiscall', None, ret='eax', gen=_obj,
  note='batch200; eax = (dword at +0x417 >> 1) with al masked to 1; upper eax bits kept')
S(0x5fa630, 'readGlobal724270 (unnamed)', 'cdecl', None, ret='eax', gen=_global,
  note='batch200; reads the dword global 0x724270')
S(0x5b7d30, 'copyField8to4 (unnamed)', 'thiscall', None, ret=None, gen=_obj,
  note='batch200; [this+4] = [this+8]')


# batch201 (src/batch201.cpp)
def _obj8(c, n=0x100):
    return [_rnd(c, n)]


def _set_clear(c):
    obj = _rnd(c, 0x100)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _src3(c):
    obj = _rnd(c, 0x100)
    src = _rnd(c, 12)
    return [obj, src]


def _mode(c):
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 4, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xffffffff, c.rng.getrandbits(32)]))
    c.emu.w32(obj + 8, c.rng.choice([0, 1, 2, 3, 4]))
    return [obj]


def _six(c):
    return [c.rng.getrandbits(32) for _ in range(6)]


def _pair(c):
    p = _rnd(c, 8)
    return [p]


S(0x441870, 'setMaskedFlags (GUESS)', 'thiscall', None, ret=None, gen=_set_clear, note='batch201; [this+0x30] masked set')
S(0x4cf170, 'resetPair (GUESS)', 'stdcall', None, ret=None, gen=_pair, note='batch201; p[0]=0, p[1]=-1')
S(0x4dcd70, 'copyVec3Flag (GUESS)', 'thiscall', None, ret=None, gen=_src3, note='batch201; copy 3 dwords, or 0x100000')
S(0x65f530, 'noop6 (GUESS)', 'stdcall', None, ret=None, gen=_six, note='batch201; empty, ret 0x18')


# batch202 (src/batch202.cpp)
def _ptr_obj(c):
    p = _rnd(c, 0x40) if c.rng.random() < 0.67 else 0
    return [p]


def _list_key(c):
    obj = _rnd(c, 0x40)
    nodes = [_rnd(c, 0x40) for _ in range(c.rng.randint(0, 4))]
    head = nodes[0] if nodes else 0
    c.emu.w32(obj + 0xc, head)
    for i, n in enumerate(nodes):
        nxt = nodes[i + 1] if i + 1 < len(nodes) else 0
        c.emu.w32(n + 0xc, nxt)
        c.emu.w32(n + 0x23, c.rng.choice([0x1234, 0x5678, c.rng.getrandbits(32)]))
    key = c.rng.choice([0x1234, 0x5678, c.rng.getrandbits(32)])
    if nodes and c.rng.random() < 0.5:
        key = c.emu.r32(nodes[c.rng.randrange(len(nodes))] + 0x23)
    return [obj, key]


def _mode_run(c):
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 4, c.rng.getrandbits(32))
    c.emu.w32(obj + 8, c.rng.choice([0, 1, 2, 3, 4]))
    return [obj, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, c.rng.getrandbits(32)])]


def _vt_obj(c):
    obj = _rnd(c, 0x100)
    if c.rng.random() < 0.7:
        inner = _rnd(c, 0x40)
        vt = c.emu.logging_vtable('inner%x' % inner, 4, impl={0x8: lambda em, a: (0, None)})
        c.emu.w32(inner, vt)
        c.emu.w32(obj + 0x6a, inner)
    else:
        c.emu.w32(obj + 0x6a, 0)
    return [obj]


S(0x43abb0, 'clearFlags (GUESS)', 'stdcall', None, ret=None, gen=_ptr_obj, note='batch202; null-checked')
S(0x45f370, 'findNodeKey (GUESS)', 'thiscall', None, ret='eax', gen=_list_key, note='batch202; list search')
S(0x59d430, 'setModeAndRun (GUESS)', 'thiscall', None, ret=None, gen=_mode_run,
  note='batch202; calls original 0x59d450')
S(0x5abcb0, 'flagAndNotify (GUESS)', 'thiscall', None, ret=None, gen=_vt_obj, note='batch202; vtable slot 2 tail call')


# batch203 (src/batch203.cpp)
def _obj_flags(c):
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 0x14, c.rng.getrandbits(32))
    return [obj, c.rng.getrandbits(32)]


def _flag_obj(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    # 0x634273 (free-style release, cdecl(p, n)) is stubbed: the exe faults on random objects. The stub stores n in a
    # heap slot, so a wrong size argument shows in the memory compare.
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    ss.patch(c, 0x634273, ss.code(c, b'\x8b\x44\x24\x08' + b'\xb9' + ss.P(slot) + b'\x89\x01\xc3'))
    _flush_heap_code(c)
    return [obj, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _ctor(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x600)
    ss.patch(c, 0x5e0e10, ss.rec(c, 2, ret=0, log=True))   # base ctor stubbed (it faults on random fields)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _p_arg(c):
    return [_rnd(c, 0x40)]


def _store(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    tgt = _rnd(c, 0x400)     # big enough that the write at +0x216 lands below the heap bump pointer (compared)
    c.emu.w32(obj + 0x18, tgt)
    ret_buf = _rnd(c, 0x40)                                  # what 0x5003d0 returns: a valid pointer to a dword
    ss.patch(c, 0x5003d0, ss.rec(c, 1, ret=ret_buf, log=True))
    p = _rnd(c, 8)
    c.emu.w32(p + 4, _rnd(c, 0x40))
    return [obj, p]


S(0x43e170, 'callThenClearBit0 (GUESS)', 'thiscall', None, ret=None, gen=_obj_flags, note='batch203; calls 0x45fa00')
S(0x4d24b0, 'setVtableRelease (GUESS)', 'thiscall', None, ret='eax', gen=_flag_obj, note='batch203; calls 0x634273')
S(0x5e0ff0, 'ctorAfterBase (GUESS)', 'thiscall', None, ret='eax', gen=_ctor, note='batch203; calls 0x5e0e10')
S(0x4edcb0, 'readPlusBaseCall (GUESS)', 'stdcall', None, ret='eax', gen=_p_arg, note='batch203; calls 0x4e3d60')
S(0x51ab70, 'storeThroughPtr (GUESS)', 'thiscall', None, ret=None, gen=_store, note='batch203; calls 0x5003d0')


# batch204 (src/batch204.cpp): vtable wrappers. Fake objects use logging_vtable (offsets are byte offsets).
import math as _math
from pilot import f32 as _f32
from pilot import F


def _vt_obj_with(c, slots, argwords):
    return c.emu.logging_vtable('o%x' % c.rng.getrandbits(16), 0x40, impl=slots, argwords=argwords)


def _slot70(c):
    obj = _rnd(c, 0x40)
    buf = _rnd(c, 0x10)
    c.emu.w32(buf, c.rng.getrandbits(32))
    r = buf if c.rng.random() < 0.7 else 0
    c.emu.w32(obj, _vt_obj_with(c, {0x70: lambda em, a, r=r: (r, None)}, {0x70: 1}))
    return [obj, c.rng.getrandbits(32)]


def _slot4f(c):
    inner = _rnd(c, 0x40)
    c.emu.w32(inner, _vt_obj_with(c, {0x4: lambda em, a: (0, None)}, {0x4: 1}))
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x5c, inner)
    return [self_, F(_f32(c.rng.uniform(-100, 100)))]


def _slot58(c):
    obj = _rnd(c, 0x100)
    ret_v = c.rng.getrandbits(32)
    vt = _vt_obj_with(c, {0x58: lambda em, a, v=ret_v: (v, None)}, {0x58: 1})
    inner = _rnd(c, 0x40)
    c.emu.w32(inner, vt)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, inner)
    c.emu.w32(0x70039c, rm)
    self_ = _rnd(c, 0x40)
    return [self_, c.rng.getrandbits(32)]


def _slot84(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    buf = _rnd(c, 0x10)
    vt = _vt_obj_with(c, {0x84: lambda em, a, b=buf: (b, None)}, {0x84: 1})
    c.emu.w32(obj, vt)
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    # 0x4f21f0 stub: stores ecx (the returned object) in a heap slot, so the value is compared
    ss.patch(c, 0x4f21f0, ss.code(c, b'\x89\x0d' + ss.P(slot) + b'\xc3'))
    return [obj]


S(0x4cf3f0, 'vtSlot70Deref (GUESS)', 'thiscall', None, ret='eax', gen=_slot70, note='batch204; vtable slot 0x70')
S(0x5139b0, 'vtSlot4Float (GUESS)', 'thiscall', None, ret=None, gen=_slot4f, note='batch204; vtable slot 4, float arg')
S(0x5eb770, 'storeVtSlot58 (GUESS)', 'thiscall', None, ret=None, gen=_slot58, note='batch204; global 0x70039c, slot 0x58')
S(0x5630f0, 'callSlot84Reset (GUESS)', 'thiscall', None, ret=None, gen=_slot84, note='batch204; slot 0x84, calls 0x4f21f0')


# batch205 (src/batch205.cpp)
def _flush_heap_code(c):
    """Stub code written into the heap is reused at the same addresses by the next case; drop Unicorn's translations
    for the heap so the new bytes run (reset_stubs only flushes the stub area)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)   # patched exe functions


def _free_stub(c, slot_name=None):
    """cdecl(p, n) stand-in for 0x634273: stores n in a heap slot (the size constant becomes observable)."""
    import serial_stubs as ss
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    ss.patch(c, 0x634273, ss.code(c, b'\x8b\x44\x24\x08' + b'\xb9' + ss.P(slot) + b'\x89\x01\xc3'))
    _flush_heap_code(c)


def _ctor_flags(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    ss.patch(c, 0x5edea0, ss.rec(c, 0, ret=0, log=True))
    _free_stub(c)
    return [obj, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _ctor_flags2(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    ss.patch(c, 0x5421b0, ss.rec(c, 0, ret=0, log=True))
    _free_stub(c)
    return [obj, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _read_two(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    vals = [c.rng.getrandbits(32) for _ in range(2)]
    ss.patch(c, 0x4e5e60, ss.seqr(c, 0, vals))
    return [_rnd(c, 0x100), obj]


S(0x5efd70, 'ctorRelease (GUESS)', 'thiscall', None, ret='eax', gen=_ctor_flags, note='batch205; calls 0x5edea0, 0x634273')
S(0x5422b0, 'baseRelease (GUESS)', 'thiscall', None, ret='eax', gen=_ctor_flags2, note='batch205; calls 0x5421b0, 0x634273')
S(0x5c5bb0, 'readTwo (GUESS)', 'thiscall', None, ret=None, gen=_read_two, note='batch205; calls 0x4e5e60 twice')


# batch206 (src/batch206.cpp)
def _cf_obj(c):
    r = c.rng.getrandbits(32)
    a = _rnd(c, 0x100)
    vt = _vt_obj_with(c, {0x3c: lambda em, x: (0, None), 0x44: lambda em, x, r=r: (r, None)}, {0x3c: 1, 0x44: 1})
    c.emu.w32(a, vt)
    self_ = _rnd(c, 0x100)
    return [self_, a]


def _rm_then_self(c):
    obj = _rnd(c, 0x100)
    ret58 = c.rng.getrandbits(32)
    vt58 = c.emu.logging_vtable('o58', 0x40, impl={0x58: lambda em, x, v=ret58: (v, None)}, argwords={0x58: 1})
    c.emu.w32(obj, vt58)
    rm = _rnd(c, 0x100)
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    self_ = _rnd(c, 0x100)
    vt30c = c.emu.logging_vtable('self30c', 0xc4, argwords={0x30c: 2})
    c.emu.w32(self_, vt30c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5c5cf0, 'clearFlagCallTwo (GUESS)', 'thiscall', None, ret='eax', gen=_cf_obj, note='batch206; calls a vtable 0x3c and 0x44')
S(0x512e70, 'callViaRmThenSelf (GUESS)', 'thiscall', None, ret=None, gen=_rm_then_self, note='batch206; rm global, vtable 0x58 and 0x30c')


def _seq_rec(c, addr, nargs, rets):
    """Recorder for a thiscall callee called up to eight times: per call it stores ecx and its nargs stack words in its
    own log row and returns rets[i] (wrapping after eight); pops 4 * nargs. Patched with a plain jmp (keeps eax).
    Returns the log address (rows of 4 * (nargs + 1) bytes). Added 2026-10-12 for the 0x5003d0/0x5002f0 call shape."""
    import struct
    import serial_stubs as ss
    rets = (list(rets) + [rets[-1]] * 8)[:8]
    row = 4 * (nargs + 1)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    log = c.emu.alloc(8 * row, 4)
    c.emu.wbytes(log, bytes(8 * row))
    tab = c.emu.alloc(32, 4)
    c.emu.wbytes(tab, b''.join(ss.P(v) for v in rets))
    b = b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\x6b\xc0' + bytes([row]) + b'\x05' + ss.P(log) + b'\x89\x08'
    for i in range(nargs):
        b += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + b'\x89\x50' + bytes([4 + 4 * i])
    b += (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\x8b\x04\x85' + ss.P(tab) + b'\xff\x05' + ss.P(cnt)
          + b'\xc2' + struct.pack('<H', 4 * nargs))
    stub = ss.code(c, b)
    c.emu.wbytes(addr, b'\xe9' + struct.pack('<I', (stub - (addr + 5)) & 0xffffffff))
    c.emu._image_dirty = True
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    return log


# batch207 (src/batch207.cpp)
def _chain_spec(slot):
    def gen(c):
        import serial_stubs as ss
        value = c.rng.getrandbits(32)
        # sparse vtable: one logged stub at the slot, zero words elsewhere (a full logging_vtable of 0x1c0 slots
        # exhausts the stub pool)
        base = c.emu.logging_vtable('chain%x' % slot, 1, impl={0: lambda em, a, v=value: (v, None)},
                                        argwords={0: 1 if slot == 0x6b4 else 0})
        vt = c.emu.alloc(slot + 4, 4)
        c.emu.w32(vt + slot, c.emu.r32(base))
        inner = _rnd(c, 0x40)
        c.emu.w32(inner, vt)
        self_ = _rnd(c, 0x100)
        c.emu.w32(self_ + 0x1c, inner)
        a = _rnd(c, 0x40)
        c.emu.w32(a + 8, _rnd(c, 0x40))
        res = _rnd(c, 0x40)
        # 2026-10-12: 0x5003d0 and 0x5002f0 are recorded per call (ecx and their ONE stack word each, ret 4), so the
        # index pushed for 0x5003d0 and the value popped by 0x5002f0 are both compared (docs/20-unclaimed-22.md).
        _seq_rec(c, 0x5003d0, 1, [res])
        _seq_rec(c, 0x5002f0, 1, [c.rng.getrandbits(32)])
        return [self_, a]
    return gen


def _ctor_flags3(c):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    ss.patch(c, 0x5ebbd0, ss.rec(c, 0, ret=0, log=True))
    _free_stub(c)
    return [obj, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x5ebc70, 'baseRelease (GUESS)', 'thiscall', None, ret='eax', gen=_ctor_flags3, note='batch207; calls 0x5ebbd0, 0x634273')


# batch208 (src/batch208.cpp)
def _sparse_vt(c, slot, fn, argwords):
    """A vtable with one logged stub at byte offset slot and zero words elsewhere (see batch207)."""
    base = c.emu.logging_vtable('sp%x' % slot, 1, impl={0: fn}, argwords={0: argwords})
    vt = c.emu.alloc(slot + 4, 4)
    c.emu.w32(vt + slot, c.emu.r32(base))
    return vt


def _store_stub(c, nwords, ret_bytes):
    """A cdecl or thiscall stand-in that stores its first nwords stack words (or ecx) and returns; written in the heap."""
    import serial_stubs as ss
    slots = [c.emu.alloc(4, 4) for _ in range(nwords)]
    for s_ in slots:
        c.emu.w32(s_, 0)
    code = b''
    for k, s_ in enumerate(slots):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * k]) + b'\xa3' + ss.P(s_)
    code += b'\xc3' if ret_bytes == 0 else b'\xc2' + ss.struct.pack('<H', ret_bytes)
    return slots, code


def _ctor_flags4(c, base_addr, relname):
    import serial_stubs as ss
    obj = _rnd(c, 0x100)
    ss.patch(c, base_addr, ss.rec(c, 0, ret=0, log=True))
    slots45, code45 = _store_stub(c, 1, 0)
    ss.patch(c, 0x45c510, ss.code(c, code45))
    slots46, code46 = _store_stub(c, 2, 0)
    ss.patch(c, 0x4690b0, ss.code(c, code46))
    _flush_heap_code(c)
    return [obj, c.rng.choice([0, 1, 2, 3, 4, 5, 6, c.rng.getrandbits(32)])]


def _ctor46a(c):
    return _ctor_flags4(c, 0x46a4f0, '46a')


def _ctor485(c):
    return _ctor_flags4(c, 0x43ea20, '485')


def _vt1d8(c):
    import serial_stubs as ss
    self_ = _rnd(c, 0x100)
    if c.rng.random() < 0.6:
        obj = _rnd(c, 0x100)
        vt = _sparse_vt(c, 0x1d8, lambda em, a: (0, None), 2)
        c.emu.w32(obj, vt)
        c.emu.w32(self_ + 0x54, obj)
    else:
        c.emu.w32(self_ + 0x54, 0)
    slot_c = c.emu.alloc(4, 4)
    c.emu.w32(slot_c, 0)
    slot_s = c.emu.alloc(4, 4)
    ss.patch(c, 0x4cbe80, ss.code(c, b'\x89\x0d' + ss.P(slot_c) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(slot_s)
                                  + b'\xc2\x04\x00'))   # stores ecx and its stack word, pops 4
    _flush_heap_code(c)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x46a770, 'ctorRelease46a (GUESS)', 'thiscall', None, ret='eax', gen=_ctor46a, note='batch208; calls 0x46a4f0, 0x4690b0, 0x45c510')
S(0x485bb0, 'baseRelease485 (GUESS)', 'thiscall', None, ret='eax', gen=_ctor485, note='batch208; calls 0x43ea20, 0x4690b0, 0x45c510')
S(0x4da2f0, 'vtSlot1d8OrBase (GUESS)', 'thiscall', None, ret='eax', gen=_vt1d8, note='batch208; vtable 0x1d8 or 0x4cbe80')


# batch209 (src/batch209.cpp)
def _reset3_spec(c):
    import serial_stubs as ss
    _rnd(c, 0x100)   # padding: the stub reads [ecx-0x55], which must stay in the mapped heap
    obj = _rnd(c, 0x100)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(16, 4)
    c.emu.wbytes(ring, bytes(16))
    # 480fd0 stand-in: store ecx at ring[cnt], then cnt++ (so the three sub-objects are checked in order)
    vring = c.emu.alloc(16, 4)
    # also records [this] (= ecx - 0x55) at each call: the vtable word the exe wrote just before the call
    code = (b'\x8b\x41\xab' + b'\x8b\x15' + ss.P(cnt) + b'\x89\x04\x95' + ss.P(vring)
            + b'\xa1' + ss.P(cnt) + b'\x89\x0c\x85' + ss.P(ring) + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    ss.patch(c, 0x480fd0, ss.code(c, code))
    _free_stub(c)
    _flush_heap_code(c)
    return [obj, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


def _float624(c):
    import serial_stubs as ss
    import math
    fv = _f32(c.rng.choice([0.0, -0.0, 1.5, -2.25, 1e6, math.nan, c.rng.uniform(-100, 100)]))
    r = c.emu.alloc(8, 4)
    c.emu.wf32(r, fv)
    slot_c = c.emu.alloc(4, 4)
    slot_f = c.emu.alloc(4, 4)
    code = (b'\x89\x0d' + ss.P(slot_c) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(slot_f)
            + b'\xb8' + ss.P(r) + b'\xc2\x04\x00')
    ss.patch(c, 0x5003d0, ss.code(c, code))   # stores ecx and its stack word, returns r, pops 4
    _flush_heap_code(c)
    _flush_heap_code(c)
    a = _rnd(c, 0x40)
    c.emu.w32(a + 4, _rnd(c, 0x40))
    self_ = _rnd(c, 0x40)
    objv = _rnd(c, 0x40)
    vt = _sparse_vt(c, 0x624, lambda em, x: (0, None), 1)
    c.emu.w32(objv, vt)
    c.emu.w32(self_ + 0x18, objv)
    return [self_, a]


S(0x4879b0, 'resetThreeRelease (GUESS)', 'thiscall', None, ret='eax', gen=_reset3_spec,
  note='batch209; three 480fd0 calls, flag release 0x634273')
S(0x5081f0, 'floatSlot624 (GUESS)', 'thiscall', None, ret=None, gen=_float624, note='batch209; 5003d0 then vtable 0x624')


# batch210 (src/batch210.cpp)
def _multi_vt(c, slots):
    """Sparse vtable: slots = {byte_offset: (impl, argwords)}; one logged stub per slot, zero words elsewhere."""
    top = max(slots) + 4
    vt = c.emu.alloc(top, 4)
    for off, (impl, aw) in slots.items():
        base = c.emu.logging_vtable('mv%x' % off, 1, impl={0: impl}, argwords={0: aw})
        c.emu.w32(vt + off, c.emu.r32(base))
    return vt


def _call_release(c):
    obj = _rnd(c, 0x100)
    a = c.rng.getrandbits(32)
    vt = _multi_vt(c, {0x3c: (lambda em, x: (0, None), 1),
                       0x14: (lambda em, x, v=c.rng.choice([0, 1, 0xdead]): (v, None), 0),
                       0x0: (lambda em, x: (0, None), 1)})
    c.emu.w32(obj, vt)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x44, obj if c.rng.random() < 0.9 else 0)
    return [self_, a]


def _two_pairs(c):
    obj = _rnd(c, 0x100)
    rbuf = _rnd(c, 0x40)
    r_val = rbuf if c.rng.random() < 0.8 else 0
    # the 0x318 slot returns r_val for both calls; the 0x31c slot on rbuf takes two words
    vt_obj = _multi_vt(c, {0x318: (lambda em, x, v=r_val: (v, None), 1)})
    vt_r = _multi_vt(c, {0x31c: (lambda em, x: (0, None), 2)})
    c.emu.w32(obj, vt_obj)
    c.emu.w32(rbuf, vt_r)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x5c, obj if c.rng.random() < 0.9 else 0)
    return [self_]


S(0x4415f0, 'callAndMaybeRelease (GUESS)', 'thiscall', None, ret=None, gen=_call_release,
  note='batch210; vtable 0x3c, 0x14, 0')
S(0x561e30, 'twoPairs (GUESS)', 'thiscall', None, ret=None, gen=_two_pairs, note='batch210; vtable 0x318 and 0x31c')


# batch211 (src/batch211.cpp): pure entry search, no calls
def _pick_spec(c):
    x = c.rng.choice([0, 1, 5, 100, c.rng.getrandbits(32)])
    n = c.rng.randint(0, 6)
    base = _rnd(c, 8 * max(n, 1))
    for i in range(n):
        key = c.rng.choice([x, (x + 1) & 0xffffffff, (x + 2) & 0xffffffff, (x - 1) & 0xffffffff, 0,
                            c.rng.getrandbits(32)])
        c.emu.w32(base + 8 * i, c.rng.getrandbits(32))
        c.emu.w32(base + 8 * i + 4, key)
    self_ = _rnd(c, 0x20)
    c.emu.w32(self_ + 4, base)
    c.emu.w32(self_ + 8, n)
    return [self_, x, c.rng.getrandbits(32)]


S(0x4cd9b0, 'pickAndSubtract (GUESS)', 'thiscall', None, ret='eax', gen=_pick_spec,
  note='batch211; pure entry search, ret 8')


# batch212 (src/batch212.cpp): pure bit-field reader, stdcall(p, n)
def _bits_spec(c):
    # a signed width can make the byte offset negative (down to about -0x0c80), so the buffer sits 0x1000 into a block
    block = c.emu.alloc(0x4000, 16)
    buf = block + 0x1000
    c.emu.wbytes(block, bytes(c.rng.getrandbits(8) for _ in range(0x4000)))
    n = c.rng.choice([0, 1, 2, 3, 8, 17, 64, 200, c.rng.getrandbits(8)])
    return [buf, n]


S(0x4e8b70, 'readBitField (GUESS)', 'stdcall', None, ret='eax', gen=_bits_spec, note='batch212; pure bit-field read')


# batch213 (src/batch213.cpp): pure entry-byte update, thiscall(a float, b)
def _topbyte_spec(c):
    import math
    n = c.rng.randint(0, 4)
    arr = _rnd(c, 40 * max(n, 1) + 8)
    for i in range(n):
        c.emu.w32(arr + 40 * i + 36, c.rng.getrandbits(32))
    obj = _rnd(c, 0x20)
    c.emu.w32(obj + 4, arr)
    self_ = _rnd(c, 0x60)
    c.emu.w32(self_ + 0x3a, obj)
    c.emu.w32(self_ + 0x3e, n)
    a = F(_f32(c.rng.choice([0.0, -0.0, 0.5, 1.0, -1.0, 2.5, 1e10, -1e10, math.nan, c.rng.uniform(-3, 3)])))
    if n and c.rng.random() < 0.5:
        b = c.rng.randrange(n)
    else:
        b = 0xffffffff
    return [self_, a, b]


S(0x5ec2b0, 'setTopByte (GUESS)', 'thiscall', None, ret=None, gen=_topbyte_spec,
  note='batch213; pure: top byte of the dword at entry+36')


# batch214 (src/batch214.cpp): SSE-unrolled sum of n/4 dwords plus n, stdcall(p, n) with n >= 0
def _sum_spec(c):
    n = c.rng.choice([0, 1, 2, 3, 4, 7, 8, 9, 15, 16, 31, 100, 0x3ff, c.rng.randrange(0, 0x1000)])
    buf = c.emu.alloc(0x1000 + 16, 16)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0x1000 + 16)))
    return [buf, n]


S(0x4d8db0, 'sumDwordsPlusCount (GUESS)', 'stdcall', None, ret='eax', gen=_sum_spec,
  note='batch214; pure sum, n >= 0 only')


def _flak_spec(c):
    import math
    self_ = _rnd(c, 0x80)
    for off in (0x5c, 0x60):
        c.emu.wf32(self_ + off, c.rng.choice([0.0, -0.0, 1.5, -2.25, 1e6, math.nan, c.rng.uniform(-100, 100)]))
    rm = _rnd(c, 0x100)
    st0 = c.rng.choice([0.0, 0.5, -3.0, 1e7, c.rng.uniform(-50, 50)])
    vt = c.emu.logging_vtable('flak1c0', 0x74, impl={0x1c0: lambda em, a, v=st0: (0, v)}, argwords={0x1c0: 2})
    c.emu.w32(rm, vt)
    c.emu.w32(0x70039c, rm)
    return [self_]


S(0x5dcc70, 'initFlakFloat (GUESS)', 'thiscall', None, ret=None, gen=_flak_spec,
  note='batch215; core list residue 19; render slot 0x1c0 returns float in st0')


def _create_anim_spec(c):
    import math
    self_ = _rnd(c, 0x100)
    r8 = c.rng.getrandbits(32)
    vt = _sparse_vt(c, 8, lambda em, x, v=r8: (v, None), 1)
    c.emu.w32(self_, vt)
    t = F(_f32(c.rng.choice([0.0, 0.5, 1.5, 1e6, c.rng.uniform(0, 100)])))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), t]


S(0x4e6d70, 'createAnim (GUESS)', 'thiscall', None, ret='eax', gen=_create_anim_spec,
  note='batch216; core list residue 19; contract t >= 0; vtable slot 8')
S(0x55cf70, 'slot6b4Wrap (GUESS)', 'thiscall', None, ret=None, gen=_chain_spec(0x6b4), note='batch207; vtable 0x6b4 then 0x5003d0, 0x5002f0')
S(0x559eb0, 'slot674Wrap (GUESS)', 'thiscall', None, ret=None, gen=_chain_spec(0x674), note='batch207; vtable 0x674 then 0x5003d0, 0x5002f0')
S(0x51b1b0, 'slot370Wrap (GUESS)', 'thiscall', None, ret=None, gen=_chain_spec(0x370), note='batch207; vtable 0x370 then 0x5003d0, 0x5002f0')
