"""specs_s580.py - unclaimed area 58 (docs/20-unclaimed-58.md)."""
from pilot import S, f32, F
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flush_heap_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _sparse_vt(c, slot, fn, argwords):
    """A vtable with one logged stub at byte offset slot and zero words elsewhere."""
    base = c.emu.logging_vtable('sp%x' % slot, 1, impl={0: fn}, argwords={0: argwords})
    vt = c.emu.alloc(slot + 4, 4)
    c.emu.w32(vt + slot, c.emu.r32(base))
    return vt


def _dword_flag(c):
    obj = _rnd(c, 0x100)
    if c.rng.random() < 0.4:
        c.emu.w32(obj + 0x45, c.rng.choice([0, 1, 0xdeadbeef]))
    return [obj, c.rng.choice([0, 1, 0xdeadbeef, c.rng.getrandbits(32)])]


S(0x5eebd0, 'setDwordIfChanged (GUESS)', 'thiscall', None, ret=None, gen=_dword_flag,
  note='batch580; conditional dword store and flag')


def _member(c):
    self_ = _rnd(c, 0x200)
    if c.rng.random() < 0.7:
        m = _rnd(c, 0x100)
        c.emu.w32(self_ + 0x1de, m)
    else:
        c.emu.w32(self_ + 0x1de, 0)
    slot_c = c.emu.alloc(4, 4)
    slot_a = c.emu.alloc(4, 4)
    c.emu.w32(slot_c, 0)
    c.emu.w32(slot_a, 0)
    # 584cc0 stand-in: stores ecx and its stack word, pops 4
    code = (b'\x89\x0d' + ss.P(slot_c) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(slot_a) + b'\xc2\x04\x00')
    ss.patch(c, 0x584cc0, ss.code(c, code))
    _flush_heap_code(c)
    return [self_]


S(0x4681d0, 'releaseMember (GUESS)', 'thiscall', None, ret=None, gen=_member,
  note='batch580; calls original 0x584cc0 when [this+0x1de] is set')


def _dispatch(c):
    import serial_stubs as ss
    self_ = _rnd(c, 0x300)
    words = {0x240: c.rng.getrandbits(16), 0x242: c.rng.getrandbits(16), 0x244: c.rng.getrandbits(16),
             0x246: c.rng.getrandbits(16), 0x24a: c.rng.getrandbits(16), 0x24c: c.rng.getrandbits(16),
             0x24e: c.rng.getrandbits(16)}
    for off, v in words.items():
        c.emu.w16(self_ + off, v)
    # 5b5420: thiscall, no args; 5b5370: thiscall, one stack word. Both store ecx (and the word) in heap slots.
    s_c1 = c.emu.alloc(4, 4)
    s_c2 = c.emu.alloc(4, 4)
    s_a2 = c.emu.alloc(4, 4)
    for s_ in (s_c1, s_c2, s_a2):
        c.emu.w32(s_, 0)
    ss.patch(c, 0x5b5420, ss.code(c, b'\x89\x0d' + ss.P(s_c1) + b'\xc3'))
    ss.patch(c, 0x5b5370, ss.code(c, b'\x89\x0d' + ss.P(s_c2) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(s_a2) + b'\xc2\x04\x00'))
    _flush_heap_code(c)
    # pointer argument: null or a dword holding zero or nonzero
    p = 0
    if c.rng.random() < 0.8:
        p = _rnd(c, 8)
        c.emu.w32(p, c.rng.choice([0, 1, 0x80000000, c.rng.getrandbits(32)]))
    # the word: one of the stored words (so a branch is taken) or a random one
    w = c.rng.choice(list(words.values()) + [c.rng.getrandbits(16)])
    c.emu.w32(self_ + 0x4c, c.rng.getrandbits(32))
    return [self_, w, p]


S(0x5b2bd0, 'dispatchWord (GUESS)', 'thiscall', None, ret='eax', gen=_dispatch,
  note='batch581; word-keyed dispatch, calls 0x5b5420 and 0x5b5370')


def _entry_name_spec(c):
    """0x438b10: the vtable's slot 0x4c writes flag 1 through its pointer; slot 0x5c returns a scripted sequence of
    (entry, flag). Stack pointers are written by the handler and not logged, so the exe and the port can differ in
    stack address without a false mismatch."""
    import serial_stubs as ss
    names = []
    for _ in range(c.rng.randint(0, 4)):
        nm = _rnd(c, 12)
        c.emu.wbytes(nm, bytes(c.rng.choice(b'abc') for _ in range(c.rng.randint(0, 5))) + b'\x00')
        names.append(nm)
    entries = []
    for nm in names:
        e = _rnd(c, 0x10)
        c.emu.w32(e + 4, nm if c.rng.random() < 0.9 else 0)
        c.emu.w32(e + 8, 0)
        entries.append(e)
    # the search string: equal to one of the names, or a fresh string
    if names and c.rng.random() < 0.6:
        s = names[c.rng.randrange(len(names))]
    else:
        s = _rnd(c, 12)
        c.emu.wbytes(s, bytes(c.rng.choice(b'abc') for _ in range(c.rng.randint(0, 5))) + b'\x00')
    seq = [(e, 1) for e in entries] + [(0, 0)]
    state = {'i': 0}

    def h4c(e, r):
        ptr = e.arg32(0)
        e.w32(ptr, 1)
        e.ret(eax=0, argbytes=4)

    def h5c(e, r):
        ptr = e.arg32(0)
        i = min(state['i'], len(seq) - 1)
        state['i'] += 1
        ent, fl = seq[i]
        e.w32(ptr, fl)
        e.ret(eax=ent, argbytes=4)

    vt = c.emu.fake_vtable('find438b10', 0x18, {0x4c: h4c, 0x5c: h5c})
    obj = _rnd(c, 0x20)
    c.emu.w32(obj, vt)
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x19, obj if c.rng.random() < 0.95 else 0)
    return [self_, s if c.rng.random() < 0.95 else 0]


S(0x438b10, 'findEntryByName (GUESS)', 'thiscall', None, ret='eax', gen=_entry_name_spec,
  note='batch582; vtable 0x4c and 0x5c with a stack out-flag (not logged)')


def _store_inner_spec(c):
    import serial_stubs as ss
    tgt = _rnd(c, 0x40)
    inner = _rnd(c, 0x80)
    c.emu.w32(inner + 0x54, tgt)
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, inner)
    a = _rnd(c, 0x20)
    c.emu.w32(a + 4, _rnd(c, 0x20))
    r = _rnd(c, 8)
    c.emu.w32(r, c.rng.getrandbits(32))
    slot_c = c.emu.alloc(4, 4)
    slot_f = c.emu.alloc(4, 4)
    c.emu.w32(slot_c, 0)
    c.emu.w32(slot_f, 0)
    # 5003d0 stand-in (one stack word): stores ecx and that word, returns r, pops 4
    code = (b'\x89\x0d' + ss.P(slot_c) + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(slot_f)
            + b'\xb8' + ss.P(r) + b'\xc2\x04\x00')
    ss.patch(c, 0x5003d0, ss.code(c, code))
    _flush_heap_code(c)
    return [self_, a]


def _cached_spec(c):
    self_ = _rnd(c, 0x200)
    vt = _sparse_vt(c, 0x2e8, lambda em, x, v=c.rng.getrandbits(32): (v, None), 1)
    c.emu.w32(self_, vt)
    c.emu.w32(self_ + 0x1d5, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x1d9, c.rng.choice([0, 0, 7, c.rng.getrandbits(32)]))
    return [self_]


S(0x55c7d0, 'storeIntoInner (GUESS)', 'thiscall', None, ret=None, gen=_store_inner_spec,
  note='batch583; calls 0x5003d0, stores through [[this+0x1c]+0x54]')
S(0x5144d0, 'cachedVtCall (GUESS)', 'thiscall', None, ret='eax', gen=_cached_spec,
  note='batch583; caches vtable 0x2e8 result at +0x1d9')


def _multi_vt(c, slots):
    """Sparse vtable: slots = {byte_offset: (impl, argwords)}; one logged stub per slot, zero words elsewhere."""
    top = max(slots) + 4
    vt = c.emu.alloc(top, 4)
    for off, (impl, aw) in slots.items():
        base = c.emu.logging_vtable('mv%x' % off, 1, impl={0: impl}, argwords={0: aw})
        c.emu.w32(vt + off, c.emu.r32(base))
    return vt


def _save_spec(slot):
    def gen(c):
        self_ = _rnd(c, 0x80)
        c.emu.w32(self_ + 4, c.rng.getrandbits(32))
        c.emu.w32(self_ + 0x48, c.rng.getrandbits(32))
        c.emu.w16(self_ + 0x4c, c.rng.getrandbits(16))
        save = _rnd(c, 0x40)
        r = c.rng.getrandbits(32)
        vt = _multi_vt(c, {slot: (lambda em, x: (0, None), 1), 0x40: (lambda em, x, v=r: (v, None), 1)})
        c.emu.w32(save, vt)
        return [self_, save]
    return gen


def _load_spec(c):
    self_ = _rnd(c, 0x80)
    c.emu.w32(self_ + 4, c.rng.getrandbits(32))
    load = _rnd(c, 0x40)
    r = c.rng.getrandbits(32)
    vt = _multi_vt(c, {0x68: (lambda em, x: (0, None), 1), 0x40: (lambda em, x, v=r: (v, None), 1)})
    c.emu.w32(load, vt)
    return [self_, load]


def _nodes_spec(c):
    self_ = _rnd(c, 0x40)
    vt = _multi_vt(c, {4: (lambda em, x: (0, None), 2)})
    c.emu.w32(self_, vt)
    arr = _rnd(c, 16)
    for k in range(4):
        c.emu.w32(arr + 4 * k, c.rng.choice([0xffffffff, c.rng.getrandbits(32), 0, 1]))
    return [self_, arr, c.rng.getrandbits(32)]


S(0x49ef50, 'saveFields (GUESS)', 'thiscall', None, ret='eax', gen=_save_spec(0x3c),
  note='batch584; core list residue 17; vtable 0x3c and 0x40')
S(0x5c3d90, 'loadFields (GUESS)', 'thiscall', None, ret='eax', gen=_load_spec,
  note='batch584; core list residue 17; vtable 0x68 and 0x40')
S(0x437ad0, 'addNodes (GUESS)', 'thiscall', None, ret=None, gen=_nodes_spec,
  note='batch584; core list residue 17; loop over vtable 4')


def _anim_save_spec(c):
    self_ = _rnd(c, 0x100)
    save = _rnd(c, 0x40)
    vt = _multi_vt(c, {0x4c: (lambda em, x: (0, None), 1), 0x60: (lambda em, x: (0, None), 1)})
    c.emu.w32(save, vt)
    return [self_, save]


def _digital_spec(c):
    self_ = _rnd(c, 0x40)
    r38 = c.rng.choice([0, 0x100, c.rng.getrandbits(32), c.rng.getrandbits(32) | 1])
    ra4 = c.rng.getrandbits(32)
    vt = _multi_vt(c, {0x38: (lambda em, x, v=r38: (v, None), 2), 0xa4: (lambda em, x, v=ra4: (v, None), 1)})
    c.emu.w32(self_, vt)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4e7110, 'saveAnim (GUESS)', 'thiscall', None, ret=None, gen=_anim_save_spec,
  note='batch585; core list residue 17; float args via vtable 0x4c, byte via 0x60')
S(0x438110, 'checkActionDigital (GUESS)', 'thiscall', None, ret='eax', gen=_digital_spec,
  note='batch585; core list residue 17; vtable 0x38 and 0xa4')


