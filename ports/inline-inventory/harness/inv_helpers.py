"""inv_helpers.py - shared spec helpers for the inventory thread (inline-inventory, 2026-10-11).

Rec(c) is a call recorder for one case. Each stub it makes appends a record to a log buffer on the fake heap:
    u32 stub id, u32 ECX, then the first `nargs` stack arguments (raw dwords)
and returns the next value from its own return list (drawn from c.rng when the case is generated, so the original
and the port see the same values). Because the pilot compares every heap byte, the log checks call order, `this`
and every argument of every callee, not just the effect on the object.

    r = Rec(c)
    vt = r.vtable({0x110: r.stub(1, 2), 0x98: r.stub(2, 3, rets=[0])})   # thiscall slots, callee pops 4*nargs
    r.hook(0x4702b0, 3, 1, rets=[1])                                      # replace an exe function at its address
Hooks are cleared at the start of the next case (Rec() unhooks everything an earlier Rec hooked).
"""
import struct

_HOOKED = set()
STACK_LO, STACK_HI = 0x0ff00000 - 0x00100000, 0x0ff00000


def _is_stack(a):
    return STACK_LO <= a < STACK_HI


class Rec:
    def __init__(self, c, size=0x800):
        self.c, self.emu = c, c.emu
        for a in list(_HOOKED):
            self.emu.unhook(a)
        _HOOKED.clear()
        self.size = size
        self.log = self.emu.alloc(size, 4, fill=0xee)
        self.off = 0

    def _write(self, words):
        for w in words:
            if self.off + 4 > self.size:
                return
            self.emu.w32(self.log + self.off, w & 0xffffffff)
            self.off += 4

    def stub(self, sid, nargs, rets=None, pop=True, rand=False, ret_st0=None, writes=None, log_ecx=True, log_edx=False, quiet_args=()):
        """A handler: log (sid, ecx, args), return rets[i] for the i-th call (last value repeats; None = leave EAX).
        pop=False for cdecl. rand=True: return values drawn now from c.rng (32-bit), one per possible call.
        A stack argument that points into the emulator stack (a local of the caller) is logged as the marker
        0x57ac0000 + the dword it points at, since the original and the port lay out their frames differently.
        writes={k: value}: store a dword through pointer argument k after logging (an out parameter); a list value
        gives one value per call (last repeats); a key (k, off) writes at pointer argument k + off. log_edx=True: also log EDX (fastcall second argument). quiet_args=(k,...): stack-pointer arguments whose old contents are not logged."""
        if rand:
            rets = [self.c.rng.getrandbits(32) for _ in range(16)]
        rets = list(rets) if rets is not None else [None]
        state = {'i': 0}

        def h(emu, res):
            esp = emu.reg('esp')
            raw = [emu.r32(esp + 4 + 4 * k) for k in range(nargs)]
            args = []
            for k, a in enumerate(raw):
                if _is_stack(a):
                    # quiet_args: out-parameters whose old contents are uninitialised (only the marker is logged)
                    args += [0x57ac0000] if k in quiet_args else [0x57ac0000, emu.r32(a)]
                else:
                    args.append(a)
            ecx = emu.reg('ecx')
            if not log_ecx:
                ecx = 0
            regs = [ecx]
            if log_edx:
                regs.append(emu.reg('edx'))
            words = [sid]
            for v in regs:
                words += [0x57ac0000, emu.r32(v)] if _is_stack(v) else [v]
            self._write(words + args)
            i = state['i']
            for k, v in (writes or {}).items():
                ptr = raw[k[0]] + k[1] if isinstance(k, tuple) else raw[k]
                emu.w32(ptr, v[min(i, len(v) - 1)] if isinstance(v, list) else v)
            state['i'] += 1
            rv = rets[min(i, len(rets) - 1)]
            if ret_st0 is not None:
                emu.ret(st0=ret_st0, argbytes=4 * nargs if pop else 0)
            else:
                emu.ret(eax=rv, argbytes=4 * nargs if pop else 0)
        return h

    def vtable(self, slots, nslots=None, name='vt'):
        n = nslots or (max(slots) // 4 + 1 if slots else 1)
        return self.emu.fake_vtable(name, n, slots)

    def obj(self, size, slots=None, rnd=True, nslots=None):
        """Object of `size` random bytes whose vtable (dword 0) is a fake vtable with `slots`."""
        o = self.emu.alloc(size, 4)
        if rnd:
            self.emu.wbytes(o, bytes(self.c.rng.getrandbits(8) for _ in range(size)))
        if slots is not None:
            self.emu.w32(o, self.vtable(slots, nslots))
        return o

    def fn(self, sid, nargs, **kw):
        """A free-standing stub address (for a function pointer in data)."""
        return self.emu.stub_fn('stub%d' % sid, self.stub(sid, nargs, **kw))

    def hook(self, addr, sid, nargs, **kw):
        self.emu.hook(addr, self.stub(sid, nargs, **kw))
        _HOOKED.add(addr)


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def f32bits(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def set_global(c, addr, val):
    """Write a dword global of the exe image for this case; marks the image dirty so the next case restores it."""
    c.emu.w32(addr, val)
    c.emu._image_dirty = True
