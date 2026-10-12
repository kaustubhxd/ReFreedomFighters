"""specs_s1018.py - unclaimed-07 batch 18 (residue-07): ZVehicle::CheckActorInFront (0x514cf0).
The vehicle's actor (this+0x2af) is a logging vtable (slot +0x438 is a random bool). Its +8 object has the flag dword at
+0x3c. The float helper 0x4e0870 (fastcall, ECX/EDX logged, float in ST0) and the four vehicle helpers (thiscall, no
arguments, logged) are hooked. The float is drawn from a range that crosses the constant at 0x69eb5c."""
import struct

from pilot import S


def _boolish(c):
    """A 32-bit eax whose low byte (what the caller tests) is zero about half the time."""
    lo = 0 if c.rng.random() < 0.5 else c.rng.randint(1, 255)
    return (c.rng.getrandbits(24) << 8) | lo


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _check(c):
    e = c.emu
    self_o = _rnd(c, 0x400)
    actor = _rnd(c, 0x100)
    o8 = _rnd(c, 0x80)
    e.w32(o8 + 0x3c, c.rng.getrandbits(32))
    e.w32(actor + 8, o8)
    e.w32(actor, e.logging_vtable('actor', 0x440 // 4, impl={0x438: lambda em, a: (bv, None)},
                                  argwords={0x438: 0}))
    bv = _boolish(c)
    if c.rng.random() < 0.9:
        e.w32(self_o + 0x2af, actor)
    else:
        e.w32(self_o + 0x2af, 0)

    # the threshold at 0x69eb5c is 5000.0: draw values on both sides and exactly on it
    thr = struct.unpack('<f', struct.pack('<I', e.r32(0x69eb5c)))[0]
    pick = c.rng.random()
    if pick < 0.2:
        dval = thr
    elif pick < 0.4:
        dval = thr + 1.0
    elif pick < 0.7:
        dval = c.rng.uniform(4000.0, 6000.0)
    else:
        dval = c.rng.uniform(-20.0, 20.0)

    def fl(em, r):
        em.calllog.append(('4e0870', 0, (em.reg('ecx'), em.reg('edx')), ()))
        em.ret(st0=dval)

    e.hook(0x4e0870, fl)

    def helper(name, ret_eax):
        def h(em, r):
            em.calllog.append((name, 0, em.reg('ecx'), ()))
            em.ret(eax=ret_eax, argbytes=0)
        return h

    e.hook(0x515270, helper('515270', 0))
    e.hook(0x514f60, helper('514f60', _boolish(c)))
    e.hook(0x514d80, helper('514d80', _boolish(c)))
    e.hook(0x515100, helper('515100', 0))
    return [self_o]


S(0x514cf0, 'ZVehicle::CheckActorInFront (unknown) thiscall', 'thiscall', None, ret='al', gen=_check,
  note='unclaimed-07 batch 18; actor slot +0x438; flag at +8+0x3c; 0x4e0870 float; helpers 0x515270/0x514f60/0x514d80/0x515100')
