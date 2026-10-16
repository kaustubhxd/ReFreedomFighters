"""specs_s91003.py - hard trial (fable 2) batch 91003: 0x560580 touch-every-class-once (37 stack temporaries).
Every callee is hooked. A ctor hook (first call on a temporary) logs the call with `this` as a stack marker, writes a per-call signature
at this+8 and junk at this+0, +0x30, +0x44 (so the inlined base destructor's stores become observable); the 0x57c7c0 ctor also signs its
three member sub-objects at +0x190/+0x23c/+0x264 (+4). A dtor hook logs the signature it finds at this+8 (member dtors: this+4), which pins
each destructor call to the temporary that was constructed. [eng+0x9b]->slot 0x34(obj) logs obj[0], obj[8], obj[0x30], obj[0x44].
0x633654 (cookie check) hooked."""
from pilot import S
from recruits_util import sysobj, clear_hooks, hook_rec, _HOOKED

CTORS = [0x561020, 0x565840, 0x565b90, 0x566bc0, 0x561160, 0x564460, 0x567720, 0x569380, 0x5696b0, 0x56ad80, 0x56b2d0, 0x56c810, 0x56db70,
         0x56e990, 0x56fea0, 0x571960, 0x572360, 0x572e40, 0x573590, 0x574c60, 0x575d50, 0x5773f0, 0x577830, 0x578560, 0x57a100, 0x57a3b0,
         0x57a440, 0x57abc0, 0x57baa0, 0x573650, 0x57bd90, 0x57c100, 0x57c460, 0x57c7c0, 0x57f1b0, 0x57aea0]
DTORS = [0x565870, 0x566c90, 0x569730, 0x578710, 0x43de70]
MDTORS = [0x4ccf60, 0x4cce40]
HEAP_LO, HEAP_HI = 0x20000000, 0x30000000


def _g560580(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sigs = [r.getrandbits(32) for _ in range(64)]
    junk = [r.getrandbits(32) for _ in range(256)]
    cnt = [0]

    def mark(v):
        return v if HEAP_LO <= v < HEAP_HI else 0x57ac0000

    def mk(addr, kind, nargs=0):
        def h(em, res):
            this = em.reg('ecx')
            k = cnt[0]
            cnt[0] += 1
            rec = [kind, addr, mark(this)]
            if kind == 'ctor':
                em.w32(this, junk[(4 * k) % 256])
                em.w32(this + 8, sigs[k % 64])
                em.w32(this + 0x30, junk[(4 * k + 1) % 256])
                em.w32(this + 0x44, junk[(4 * k + 2) % 256])
                if addr == 0x57c7c0:
                    for off in (0x190, 0x23c, 0x264):
                        em.w32(this + off + 4, sigs[(k + off) % 64])
            elif kind == 'dtor':
                rec.append(em.r32(this + 8))
            else:
                rec.append(em.r32(this + 4))
            rec += [em.arg32(i) for i in range(nargs)]
            em.calllog.append(tuple(rec))
            em.ret(eax=junk[(4 * k + 3) % 256], argbytes=4 * nargs)
        e.hook(addr, h)
        _HOOKED.add(addr)
    for a in CTORS:
        mk(a, 'ctor', 3 if a == 0x573650 else 0)
    for a in DTORS:
        mk(a, 'dtor')
    for a in MDTORS:
        mk(a, 'mdtor')
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'))

    def unreg(em, res):   # table slot 0x34(obj): the inlined base dtor's stores are read back here
        p = em.arg32(0)
        em.calllog.append(('unreg', mark(em.reg('ecx')), mark(p), em.r32(p), em.r32(p + 8), em.r32(p + 0x30), em.r32(p + 0x44)))
        em.ret(eax=junk[cnt[0] % 256], argbytes=4)
    sysobj(c, slots={}, table_slots={0x34: e.stub_fn('unreg', unreg)}, table_size=0x40)
    return []


S(0x560580, 'GUESS TouchAllGameObjectClasses', 'cdecl', None, ret=None, gen=_g560580, note='batch91003')
