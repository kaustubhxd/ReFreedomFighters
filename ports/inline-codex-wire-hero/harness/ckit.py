"""ckit.py - stub kit for the climb thread's specs.

rvt(e, name, slots, nslots): a fake vtable whose slots are Python handlers. slots = {byte_off: (nargs, fn)}; fn(e, this,
args) returns (eax, st0, log) where log is what goes into e.calllog (use contents, not stack addresses, since the
original and the port have different stack frames). Slots not listed stop the run ('unstubbed virtual call').
"""
import struct


def rvt(e, name, slots, nslots=None):
    nslots = nslots or (max(slots) // 4 + 1)
    hs = {}
    for off, sv in slots.items():
        nargs, fn = sv[0], sv[1]
        pop = sv[2] if len(sv) > 2 else 4 * nargs   # third item: bytes the callee pops (0 for cdecl/varargs)

        def h(e, r, off=off, nargs=nargs, fn=fn, pop=pop):
            args = [e.arg32(k) for k in range(nargs)]
            eax, st0, log = fn(e, e.reg('ecx'), args) if fn else (0, None, None)
            e.calllog.append((name, off, log if log is not None else tuple(args)))
            e.ret(eax=eax, argbytes=pop, st0=st0)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def obj(e, name, size, slots, nslots=None, rng=None):
    vt = rvt(e, name, slots, nslots)
    o = e.alloc(size, 4)
    if rng is not None:
        e.wbytes(o, bytes(rng.getrandbits(8) for _ in range(size)))
    e.w32(o, vt)
    return o


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def floats(e, a, n):
    return tuple(struct.unpack('<%dI' % n, e.rbytes(a, 4 * n)))


def wfloats(e, a, vals):
    for i, v in enumerate(vals):
        try:
            e.mu.mem_write(a + 4 * i, struct.pack('<f', v))
        except OverflowError:
            e.mu.mem_write(a + 4 * i, struct.pack('<f', float('inf') if v > 0 else float('-inf')))


def cstr(e, s):
    a = e.alloc(len(s) + 1, 1)
    e.wbytes(a, s + b'\0')
    return a


# CRT string imports used by striwcmp (copied from inline-batch45/harness/specs_s54.py, C-locale behaviour)
def _low(b):
    return b + 32 if 65 <= b <= 90 else b


def _rd(e, a, n=None):
    out = bytearray()
    while n is None or len(out) < n:
        b = e.mu.mem_read(a + len(out), 1)[0]
        if n is None and b == 0:
            break
        out.append(b)
    return bytes(out)


def _strchr(e, r):
    s, ch = e.arg32(0), e.arg32(1) & 0xff
    i = 0
    while True:
        b = e.mu.mem_read(s + i, 1)[0]
        if b == ch:
            e.ret(eax=s + i)
            return
        if b == 0:
            e.ret(eax=0)
            return
        i += 1


def _cmp(a, b, n):
    for i in range(n):
        x, y = _low(a[i]), _low(b[i])
        if x != y or x == 0:
            return (x - y) & 0xffffffff
    return 0


def _memicmp(e, r):
    n = e.arg32(2)
    e.ret(eax=_cmp(_rd(e, e.arg32(0), n), _rd(e, e.arg32(1), n), n) if n else 0)


def _stricmp(e, r):
    a, b = _rd(e, e.arg32(0)) + b'\0', _rd(e, e.arg32(1)) + b'\0'
    e.ret(eax=_cmp(a, b, max(len(a), len(b))) if len(a) == len(b) else _cmp(a.ljust(max(len(a), len(b)), b'\0'),
                                                                            b.ljust(max(len(a), len(b)), b'\0'),
                                                                            max(len(a), len(b))))


def crt_setup(e):
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        e.stub_import(nm, h)


# Host writes into the exe image (globals such as g_pSysInterface 0x70039c set by a spec) do not fire the emulator's
# image-write hook, so reset_image() would not restore them before the next case. Mark the image dirty on such writes
# (advice from the weapons thread, 2026-10-11).
def _mark_dirty_writes():
    import pe_emu
    P = pe_emu.PEEmu
    if getattr(P, '_climb_dirty_patch', False):
        return
    for nm in ('w8', 'w16', 'w32', 'wf32', 'wbytes'):
        orig = getattr(P, nm)

        def w(self, a, v, orig=orig):
            if self.base <= a < self.base + len(self.image):
                self._image_dirty = True
            return orig(self, a, v)
        setattr(P, nm, w)
    P._climb_dirty_patch = True


_mark_dirty_writes()
