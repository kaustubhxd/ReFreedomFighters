"""specs_s35066.py - 0x647430 (stdcall, seven stack args A..G). A, B, C, D: heap blocks (A, B 0x400 bytes, C 0x200, D 0x400); E in 0..4; the dword [D + 48E + 0xc] (0..4) selects the record of B. The five fastcall callees are
hooked in Python: 0x4de440 (ecx = 36-byte local, edx = C + 36E, stack arg F; fills the local with random bytes), 0x43e920 (ecx, edx, stack arg), 0x441a60 and 0x4de4f0 (ecx, edx), 0x4de1d0 (ecx, edx = the local):
every hook logs its register / stack arguments and the 36 bytes behind the local-buffer registers (the local's address itself is not logged)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g647430(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    data = bytes(r.getrandbits(8) for _ in range(0x24))
    loc = {'a': None}

    def mk(addr, nstack, fill=False, ecx_local=False, edx_local=False):
        def h(em, rr):
            ecx, edx = em.reg('ecx'), em.reg('edx')
            if fill:
                loc['a'] = ecx
                em.wbytes(ecx, data)
            lc = ('L', bytes(em.rbytes(ecx, 0x24))) if ecx_local else ecx
            ld = ('L', bytes(em.rbytes(edx, 0x24))) if edx_local else edx
            em.calllog.append((hex(addr), lc, ld, tuple(em.arg32(i) for i in range(nstack))))
            em.ret(eax=0, argbytes=4 * nstack)
        e.hook(addr, h)
    mk(0x4de440, 1, fill=True, ecx_local=True)
    mk(0x43e920, 1)
    mk(0x441a60, 0)
    mk(0x4de4f0, 0, ecx_local=True)
    mk(0x4de1d0, 0, edx_local=True)
    Eidx = r.randint(0, 4)
    D = rnd(c, 0x400)
    for i in range(5):
        e.w32(D + 48 * i + 0xc, r.randint(0, 4))
    return [rnd(c, 0x400), rnd(c, 0x400), rnd(c, 0x200), D, Eidx, r.getrandbits(32), r.getrandbits(32)]


S(0x647430, 'GUESS combine record of parallel arrays', 'stdcall', None, ret=None, gen=_g647430, note='batch35066')
