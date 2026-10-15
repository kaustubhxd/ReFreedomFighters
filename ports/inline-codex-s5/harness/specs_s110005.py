"""specs_s1510.py - recruits thread batch 1510: CFormationControl::FrameUpdate, SendUpdates.
REFTABs are recruits_util.reftab fakes (iterate, remove current, delete). CheckRegroup, ControlMembers and (under
FrameUpdate) SendUpdates are recorder hooks; profiling and the object table are recorders."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, reftab
from unicorn.x86_const import UC_X86_REG_EDX


def _sys(c):
    r = c.rng
    stamp = r.getrandbits(64)

    def setedx(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, (stamp >> 32) + k)
    target = obj(c, 0x20, {0x128: pystub(c, 3, deref={1: 2})})
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=stamp & 0xffffffff, side=setedx),
                          0x178: pystub(c, 3), 0x17c: pystub(c, 3)},
                table_slots={0x58: pystub(c, 1, ret=target)})
    c.emu.wf32(so + 0x9c7, r.choice([0.0, 1.0]))
    c.emu.wf32(so + 0x9c3, r.choice([0.0, 1.0, float('nan')]))


def _formations(c):
    r = c.rng
    fl = []
    for i in range(r.randint(0, 4)):
        f = rnd(c, 0xa0)
        mem = [rnd(c, 0x20) for _ in range(r.randint(0, 4))]
        c.emu.w32(f + 4, reftab(c, mem) if r.random() < 0.85 else 0)
        evs = []
        for j in range(r.randint(0, 3)):
            ev = rnd(c, 0x10)
            evs.append(ev)
        c.emu.w32(f + 8, reftab(c, evs) if r.random() < 0.85 else 0)
        fl.append(f)
    s = rnd(c, 0x80)
    c.emu.w32(s + 0x48, reftab(c, fl) if r.random() < 0.9 else 0)
    return s


def _send(c):
    clear_hooks(c)
    _sys(c)
    c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
    return [_formations(c)]



S(0x5b7420,"CFormationControl SendUpdates","thiscall",None,ret=None,gen=_send)
