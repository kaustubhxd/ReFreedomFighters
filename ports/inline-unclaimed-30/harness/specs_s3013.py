"""specs_s3013.py - unclaimed-30 batch 13 (docs/20-unclaimed-30.md, claim 1): ZPlayer::DragBody (0x4831d0). The message table (engine
+0x9b) gets slots 0x4c, 0x58, 0x114 (five stack words on the bit-clear path, six on the bit-set path, so the table is built per case),
the player has slots 0x514 / 0x594, the geometry has 0x128, and the object of slot 0x58 has 0x128. All logged with arguments. The
bit-set path is an exe defect: it leaves a pushed word on the stack, so the exe jumps to garbage on return and faults. The spec
covers only the bit-clear path; the claim table records path B as not verified."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, log_args


def _drag(c):
    e = c.emu
    r = c.rng
    set_bits = False   # path B (bits 0x1800 set) faults in the exe: see the claim table; only path A is compared
    flags = r.getrandbits(32)
    if set_bits:
        flags |= 0x1000 if r.random() < 0.5 else 0x800
    else:
        flags &= ~0x1800 & 0xffffffff
    player = rnd(c, 0x500)
    e.w32(player + 0x417, flags)
    e.w32(player + 0x413, r.getrandbits(32))
    tobj = rnd(c, 0x40)
    e.w32(tobj, vtable(c, 'dragt', 0x60, argwords={0x128: 1}))
    geom = rnd(c, 0x40)
    e.w32(geom, vtable(c, 'dragg', 0x60, argwords={0x128: 1, 0x594: 1}))
    e.w32(player, vtable(c, 'dragp', 0x600, argwords={0x514: 0, 0x594: 1}))
    words = [r.getrandbits(16) for _ in range(4)]
    nw = 6 if set_bits else 5
    msg = e.alloc(0xb00)

    def slot4c(em, rr):
        # the first call pushes two words (this, 0); the second pushes one (the geometry): pop what was pushed
        k = sum(1 for t in em.calllog if t[0] == 'dragmsg' and t[1] == 0x4c)
        nwords = 2 if k == 0 else 1
        em.calllog.append(('dragmsg', 0x4c, em.reg('ecx'), tuple(log_args(em, nwords, {}))))
        em.ret(eax=0x1000 + k, argbytes=4 * nwords)

    def slot58(em, rr):
        em.calllog.append(('dragmsg', 0x58, em.reg('ecx'), ()))
        em.ret(eax=tobj, argbytes=0)

    def slot114(em, rr):
        raw = [em.arg32(i) for i in range(nw)]
        em.calllog.append(('dragmsg', 0x114, em.reg('ecx'), tuple(log_args(em, nw, {}))))
        em.ret(eax=words[len(em.calllog) % 4], argbytes=4 * nw)
    e.w32(msg, e.fake_vtable('dragmsg', 0x80, {0x4c: slot4c, 0x58: slot58, 0x114: slot114}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    return [player, geom]


S(0x4831d0, 'ZPlayer::DragBody', 'thiscall', None, gen=_drag, n=300)
