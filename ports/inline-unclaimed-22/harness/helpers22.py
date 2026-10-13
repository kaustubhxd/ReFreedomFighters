"""helpers22.py - shared spec helpers for unclaimed area 22 (see docs/20-unclaimed-22.md)."""
import struct
import serial_stubs as ss



def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flush_heap_code(c):
    """Stub code written into the heap is reused at the same addresses by the next case; drop Unicorn's translations
    for the heap and for the patched exe image."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _sparse_vt(c, slot, fn, nargs):
    """A vtable with one logged stub at byte offset slot; every other slot is zero. fn(em, args) -> (eax, st0)."""
    base = c.emu.logging_vtable('sv%x' % slot, 1, impl={0: fn}, argwords={0: nargs})
    vt = c.emu.alloc(slot + 4, 4)
    c.emu.w32(vt + slot, c.emu.r32(base))
    return vt


def _ret_const(c):
    v = c.rng.getrandbits(32)
    return lambda em, args, v=v: (v, None)


def _void(em, args):
    return (0, None)


def _stub_5003d0(c, buf):
    """0x5003d0 stand-in with the real stack shape (one stack word, ret 4). Returns buf and logs its argument."""
    ss.patch(c, 0x5003d0, ss.rec(c, 1, ret=buf, log=True))
    _flush_heap_code(c)




def jmp_patch(c, addr, stub):
    """Like ss.patch, but a plain `jmp rel32` (5 bytes). ss.patch writes `mov eax, stub; jmp eax`, which replaces the
    caller's eax on entry; use this when the callee must see (and keep) the caller's eax."""
    c.emu.wbytes(addr, b'\xe9' + struct.pack('<I', (stub - (addr + 5)) & 0xffffffff))
    c.emu._image_dirty = True


def _multi_vt(c, slots):
    """A vtable with several logged slots: slots = {byte_off: (fn, nargs)}. Other slots are zero."""
    top = max(slots) + 4
    vt = c.emu.alloc(top + 0x100, 4)   # zero padding after the table: a stale slot reads 0, not a neighbour
    for slot, (fn, nargs) in slots.items():
        base = c.emu.logging_vtable('mv%x' % slot, 1, impl={0: fn}, argwords={0: nargs})
        c.emu.w32(vt + slot, c.emu.r32(base))
    return vt


def _rec_ecx(c, addr, nargs):
    """Recorder for a thiscall callee: stores ecx and its stack words, returns 0 (ret 4 * nargs). jmp_patch keeps eax."""
    slots = [c.emu.alloc(4, 4) for _ in range(nargs + 1)]
    for sl in slots:
        c.emu.w32(sl, 0)
    code = b'\x89\x0d' + ss.P(slots[0])
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(slots[1 + i])
    code += b'\x31\xc0' + b'\xc2' + (4 * nargs).to_bytes(2, 'little')
    jmp_patch(c, addr, ss.code(c, code))
    _flush_heap_code(c)


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


def _hk(c, addr, name, nargs, eax=0, pop=None):
    """Hook the exe function at addr (both sides reach it): logs (name, ecx, stack words) in the call log, returns eax,
    pops 4 * nargs (or pop bytes; pop=0 for a cdecl callee). eax may be a callable em -> value. Added 2026-10-12 (batch243)."""
    def h(em, r):
        args = tuple(em.arg32(k) for k in range(nargs))
        em.calllog.append((name, addr, em.reg('ecx'), args))
        em.ret(eax=eax(em) if callable(eax) else eax, argbytes=4 * nargs if pop is None else pop)
    c.emu.hook(addr, h)


def _log_world(c, pslot=0x2c, deref=False):
    """Logger at 0x700390 (slot 0x20 thiscall(file, line) returns the log object; its slot 0x2c is a cdecl printf whose
    arguments are logged, ecx not) and an assert hook at 0x7003b0 that logs its call. Same shape as inline-ai specs_s709."""
    e = c.emu
    logobj = _rnd(c, 16)

    slots = tuple(pslot) if isinstance(pslot, (tuple, list)) else (pslot,)   # several printf slots (batch267)

    def printf(em, r, ps):
        fmt = em.arg32(1)
        raw = em.rbytes(fmt, 200)
        nargs = raw[:raw.index(0)].count(b'%') if 0 in raw else 0
        args = [em.arg32(k) for k in range(2 + nargs)]
        if deref:   # %s arguments that point at stack strings: log the text, not the address
            args = args[:2] + [em.rbytes(a, 64).split(b'\0')[0] for a in args[2:]]
        em.calllog.append(('log.printf', ps, None, tuple(args)))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {ps: (lambda em, r, ps=ps: printf(em, r, ps)) for ps in slots}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, r: (em.calllog.append(('assert', 0, None, ())), em.ret(eax=0))))


def _stricmp_stub(c):
    """api-ms-win-crt-string!_stricmp (cdecl): C-locale case-insensitive compare, returns the difference of the first
    differing lowered bytes. Both sides call it through the IAT slot 0x676414."""
    def h(em, r):
        a, b = em.arg32(0), em.arg32(1)
        i = 0
        while True:
            x = em.rbytes(a + i, 1)[0]
            y = em.rbytes(b + i, 1)[0]
            x = x + 32 if 65 <= x <= 90 else x
            y = y + 32 if 65 <= y <= 90 else y
            if x != y or x == 0:
                em.ret(eax=(x - y) & 0xffffffff)
                return
            i += 1
    c.emu.stub_import('_stricmp', h)


def _pyvt(c, slots):
    """A vtable whose slots are Python handlers: slots = {byte_off: handler(em, r)}; the handler must call em.ret.
    Other slots are zero (0x100 bytes of zero padding after the table)."""
    top = max(slots) + 4
    vt = c.emu.alloc(top + 0x100, 4)
    for off, h in slots.items():
        c.emu.w32(vt + off, c.emu.stub_fn('pyvt+0x%x' % off, h))
    return vt


FMOD = bytes.fromhex('d9c9d9f8dfe09e7af9ddd9c3')   # fxch; fprem loop; fstp st1; ret (area 25 anim_common)


def _install_fmod(c):
    """Point the _CIfmod import slot (0x676358, thunk 0x634dc4) at an fprem loop (fmod is exact, so this equals the CRT)."""
    fm = c.emu.alloc(32, 16)
    c.emu.wbytes(fm, FMOD)
    c.emu.w32(0x676358, fm)


def _loader(c, widths, log_ptr=True, extra=None):
    """A ZLoadGame-like object: each slot in widths ({byte_off: nbytes}) writes the next nbytes of a per-case random byte
    stream through its one pointer argument and logs (slot, pointer or None). Slot widths are a GUESS of the stream's
    field sizes; the port and the exe get the same bytes in the same call order, so the check holds whatever the real
    widths are. log_ptr=False when the pointers are stack locals (their addresses differ between the sides);
    log_ptr='heap' logs heap pointers only (the 0x20000000 arena) and None for stack ones.
    extra: {byte_off: handler(em, r)} for other slots. Added 2026-10-12 (batch246)."""
    stream = bytes(c.rng.getrandbits(8) for _ in range(0x400))
    st = {'pos': 0}

    def mk(off, n):
        def h(em, r):
            p = em.arg32(0)
            lp = p if (log_ptr is True or (log_ptr == 'heap' and 0x20000000 <= p < 0x21000000)) else None
            em.calllog.append(('load', off, None, (lp, n)))
            k = st['pos'] % 0x300
            em.wbytes(p, stream[k:k + n])
            st['pos'] += n
            em.ret(eax=0, argbytes=4)
        return h
    slots = {off: mk(off, n) for off, n in widths.items()}
    slots.update(extra or {})
    obj = _rnd(c, 0x20)
    c.emu.w32(obj, _pyvt(c, slots))
    return obj


def _save_streams(c, slots):
    """Two ZSaveGame-like objects A and B whose one-word slots (byte offsets in slots) log (object, slot, word) and return
    the other object, so a chained call made on the wrong stream is caught. Returns A. Added 2026-10-12 (batch247)."""
    e = c.emu
    a, b = _rnd(c, 0x20), _rnd(c, 0x20)

    def mk(name, other):
        def slot(off):
            def h(em, r):
                em.calllog.append((name, off, None, (em.arg32(0),)))
                em.ret(eax=other, argbytes=4)
            return h
        return _pyvt(c, {off: slot(off) for off in slots})
    e.w32(a, mk('sA', b))
    e.w32(b, mk('sB', a))
    return a
