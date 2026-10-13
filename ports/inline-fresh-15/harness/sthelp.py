"""sthelp.py - input builders shared by the soundtimers specs (batches 1600-1699).

Stubs are small x86 routines on the fake heap (the batch 53 pattern): each records its stack arguments and a call
count, and also the global call sequence number of its last call, so the order of calls into different stubs is
compared too (the checker compares every heap byte)."""
import struct


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


class Seq:
    """One dword on the heap that every stub increments."""
    def __init__(self, c):
        self.addr = c.emu.alloc(4, 4)


def stub(c, seq, nargs, ret=0, fld=None, skip=(), retfn=None, pop=True):
    """Thiscall/stdcall-style stub: records args (except `skip`), count, last sequence number; returns `ret` in eax.
    fld: address of a float to load into ST0 before returning (for float-returning callees).
    retfn: None, or a list of (argidx, value, ret) - if arg argidx == value, return that ret instead (a lookup)."""
    rec = c.emu.alloc(4 * (nargs + 2), 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)                      # inc [count]
    code += b'\xff\x05' + struct.pack('<I', seq.addr)                             # inc [seq]
    code += b'\xa1' + struct.pack('<I', seq.addr) + b'\xa3' + struct.pack('<I', rec + 4 * nargs + 4)
    if fld is not None:
        code += b'\xd9\x05' + struct.pack('<I', fld)
    tail = b'\xb8' + struct.pack('<I', ret & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs if pop else 0)
    if retfn:
        # for each (argidx, value, r): mov eax,[esp+4+4i]; cmp eax,value; jne next; mov eax,r; ret n
        for ai, val, r in retfn:
            blk_ret = b'\xb8' + struct.pack('<I', r & 0xffffffff) + b'\xc2' + struct.pack('<H', 4 * nargs if pop else 0)
            code += b'\x8b\x44\x24' + bytes([4 + 4 * ai]) + b'\x3d' + struct.pack('<I', val & 0xffffffff)
            code += b'\x75' + bytes([len(blk_ret)]) + blk_ret
    code += tail
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def obj(c, size, slots, nslots=None):
    """Random object of `size` bytes whose vtable has the given {offset: code} slots (others are 0)."""
    o = rnd(c, size)
    vt = c.emu.alloc((max(slots) + 4) if slots else 4, 4)
    for off, code in slots.items():
        c.emu.w32(vt + off, code)
    c.emu.w32(o, vt)
    return o


def ticks(c):
    r = c.rng
    k = r.random()
    if k < 0.7:
        return r.randint(0, 1 << 22)
    if k < 0.85:
        return r.randint(0, 0x30000)
    return r.choice([0, 1, 0x1e000, 0x1dfff, 0x7fffffff, 0x80000000, 0xffffffff, 0x7ffff400, r.getrandbits(32)])


def sysobj(c, t=None, dt=None, db=None, extra=None):
    """ZSysInterface stand-in at *0x70039c: +0x40 ticks, +0x48 frame step, +0x9b database/sound object."""
    s = rnd(c, 0x1c00)
    c.emu.w32(s + 0x40, ticks(c) if t is None else t)
    c.emu.wf32(s + 0x48, c.rng.uniform(0.0, 0.1) if dt is None else dt)
    if db is not None:
        c.emu.w32(s + 0x9b, db)
    for off, v in (extra or {}).items():
        c.emu.w32(s + off, v)
    c.emu.w32(0x70039c, s)
    return s


HOOKED = set()


def clear_hooks(c):
    """Remove every exe-code hook a previous case installed (pe_emu hooks persist across runs)."""
    for a in list(HOOKED):
        c.emu.unhook(a)
    HOOKED.clear()


def hook(c, seq, addr, nargs, ret=0, this=True, pop=True):
    """Replace exe function `addr` (thiscall or stdcall, callee pops nargs dwords) by a Python recorder: ECX (when
    `this`), the args, a call count and the last sequence number go to a heap record; returns `ret` in EAX."""
    rec = c.emu.alloc(4 * (nargs + 3), 4)

    def h(e, r):
        sp = e.reg('esp')
        if this:
            e.w32(rec, e.reg('ecx'))
        for i in range(nargs):
            e.w32(rec + 4 + 4 * i, e.r32(sp + 4 + 4 * i))
        e.w32(rec + 4 + 4 * nargs, e.r32(rec + 4 + 4 * nargs) + 1)
        n = e.r32(seq.addr) + 1
        e.w32(seq.addr, n)
        e.w32(rec + 8 + 4 * nargs, n)
        e.ret(eax=ret(e) if callable(ret) else ret, argbytes=4 * nargs if pop else 0)
    HOOKED.add(addr)
    c.emu.hook(addr, h)
    return rec


def sound_obj(c):
    r = c.rng
    o = rnd(c, 0x100)
    k = r.random()
    c.emu.wf32(o + 0x70, 0.0 if k < 0.4 else (float('nan') if k < 0.45 else (-0.0 if k < 0.5 else (0.2 if k < 0.6 else r.uniform(0, 5)))))
    c.emu.wf32(o + 0x88, r.uniform(0, 100))
    return o


def world(c, seq, dll_present=None, size=0x200, slots=None, dll_slots=None):
    """ZIKLNKOBJ world for the sound calls. Returns (self, cur_handle, new_handle)."""
    r = c.rng
    clear_hooks(c)
    hc, hn = r.getrandbits(32) | 1, r.getrandbits(32) & ~1
    cur = sound_obj(c) if r.random() < 0.75 else 0
    new = sound_obj(c) if r.random() < 0.85 else 0
    db = obj(c, 0x40, {0x60: stub(c, seq, 1, ret=0, retfn=[(0, hc, cur), (0, hn, new)])})
    ds = {0xf0: stub(c, seq, 1, ret=(r.getrandbits(24) << 8) | r.choice([0, 1, 0, 1, 0x80]))}
    ds.update(dll_slots or {})
    dll = obj(c, 0x40, ds)
    if dll_present is None:
        dll_present = r.random() < 0.9
    sysobj(c, db=db, extra={0x1a9f: dll if dll_present else 0})
    hook(c, seq, 0x43ec00, 6, ret=hn)
    hook(c, seq, 0x43eb80, 1, ret=hn)
    grp = rnd(c, 0x20)
    sl = {0x20: stub(c, seq, 0, ret=grp)}
    sl.update(slots or {})
    me = obj(c, size, sl)
    c.emu.w32(me + 8, rnd(c, 0x40))
    c.emu.w8(me + 0x13a, r.choice([0, 1, 1, 1, 0x40]))
    k = r.random()
    c.emu.w32(me + 0x13b, hc if k < 0.8 else (hn if k < 0.9 else r.getrandbits(32)))
    return me, hc, hn


def _cc(c, seq, slots=None):
    """A ZCharacterControl: 0x990 random bytes with plausible timers, vtable stubs for +0x64 / +0x68."""
    r = c.rng
    sl = {0x64: stub(c, seq, 1), 0x68: stub(c, seq, 2)}
    sl.update(slots or {})
    o = obj(c, 0x990, sl)
    return o


def _timers(c, o, now):
    """Fill rec(e, t) with last-play times around `now` and intervals of 0..40 s (some special values)."""
    r = c.rng
    nows = (now if now < 0x80000000 else now - (1 << 32)) / 1024.0
    for e in range(0x62):
        for t in range(3):
            p = o + 0x48 + 24 * e + 8 * t
            k = r.random()
            last = nows - r.uniform(0, 60) if k < 0.8 else (nows + r.uniform(0, 10) if k < 0.9 else r.uniform(-1e4, 1e4))
            iv = r.choice([0.0, 0.2, 0.3, 0.5, 3.0, 12.0, 30.0, 45.0]) if r.random() < 0.6 else r.uniform(0, 40)
            c.emu.wf32(p, last)
            c.emu.wf32(p + 4, iv)
    k = r.random()
    c.emu.wf32(o + 0x978, nows - r.uniform(0, 100) if k < 0.8 else (nows if k < 0.9 else nows + r.uniform(-0.01, 5)))
    if r.random() < 0.15:   # some timers exactly on the interval edge (since == interval)
        e, t = r.randint(0, 0x26), r.randint(0, 2)
        p = o + 0x48 + 24 * e + 8 * t
        c.emu.wf32(p + 4, 3.0)
        c.emu.wf32(p, nows - 3.0)


def except1(c):
    """CRT _except1 (the float->int helper 0x633910 calls it for out-of-range or NaN values): record the flag
    argument and a count, return 0.0 in ST0 like a masked exception."""
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        e.w32(rec, e.r32(e.reg('esp') + 4))
        e.w32(rec + 4, e.r32(rec + 4) + 1)
        e.ret(st0=0.0)
    c.emu.stub_import('_except1', h)
