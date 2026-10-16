"""specs_s8828.py - hitreact batch 8828: ZBoneAnim::AddCallBackAlways 0x461570. Half the cases start with no callback table (+0x6c = 0), so the
exe's operator new 0x41e290 and LINKSORTREFTAB::LINKSORTREFTAB 0x4ccad0 run (exe code in both builds) and the real table's slot 0x98 inserts;
the other half give an existing table  object whose slot 0x98 is a recording stub returning a pointer into a scratch block."""
from pilot import S, F
from wkit import rnd, stub, obj, fedge


def _gen(c):
    r = c.rng
    emu = c.emu
    self = rnd(c, 0x80)
    if r.random() < 0.5:
        emu.w32(self + 0x6c, 0)
        fail = False   # a failed new makes the exe itself call through a null table (it does not check): not a case worth comparing
        blocks = []
        sizes = emu.alloc(0x40, 4)
        emu.wbytes(sizes, bytes(0x40))

        def ml(em, rr):   # the CRT malloc under operator new and the table's own growth: a fresh zeroed block per call
            n = em.arg32(0)
            b = em.alloc(max(n, 4) + 0x20, 16)
            em.wbytes(b, bytes(max(n, 4) + 0x20))
            if len(blocks) < 15:
                em.w32(sizes + 4 * len(blocks), n)   # the requested sizes, in a heap block the compare covers
            blocks.append(b)
            em.ret(eax=b, argbytes=0)
        emu.stub_import('malloc', ml)
    else:
        blk = rnd(c, 0x40)
        tab = obj(c, 0x40, {0x98: stub(c, 3, ret=blk + 0x10)})
        emu.w32(self + 0x6c, tab)
    frame = r.choice((0.0, 7.0, 10.0, 25.0, r.uniform(-50, 500), fedge(c)))
    emu.mu.ctl_flush_tb()
    return [self, F(frame), r.choice((0x465710, r.getrandbits(32))), r.choice((0, 1, r.getrandbits(32)))]


S(0x461570, 'ZBoneAnim::AddCallBackAlways', 'thiscall', ret=None, gen=_gen)
