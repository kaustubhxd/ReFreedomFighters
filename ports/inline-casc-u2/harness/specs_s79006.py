"""specs_s79006.py - cascade u2 batch 79006: 0x513d10 (iterate resources and spawn items)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _g513d10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Set up the assert hook (required by recipe)
    def assert_hook(em, res_):
        em.ret(eax=r.getrandbits(32), argbytes=0)
    e.hook(0x7003b0, assert_hook)

    # Create a mock engine global at 0x70039c using obj helper
    eng = obj(e, 0x1000)
    e.w32(0x70039c, eng)

    # Create the tier object at engine + 0x9b
    tier = e.alloc(0xb00, 4)
    e.w32(eng + 0x9b, tier)

    # Create vtables and pointers for tier
    tier_vt = e.alloc(0x300, 4)
    e.w32(tier, tier_vt)

    # Container object at tier + 0xadc
    container = e.alloc(0x100, 4)
    container_vt = e.alloc(0x300, 4)
    e.w32(container, container_vt)
    e.w32(tier + 0xadc, container)

    # Set up vtable functions with hook_rec
    # Tier virtual method at 0x25c (returns container)
    def tier_0x25c(em, res_):
        em.ret(eax=container, argbytes=0xc)

    # Tier virtual method at 0x4c (returns ID for resource)
    def tier_0x4c(em, res_):
        em.ret(eax=r.randrange(100, 1000), argbytes=8)

    # Tier virtual method at 0x58 (resource lookup)
    def tier_0x58(em, res_):
        # Return a resource container with iterator
        res_cont = e.alloc(0x80, 4)
        res_cont_vt = e.alloc(0x300, 4)
        e.w32(res_cont, res_cont_vt)

        # Iterator object at res_cont + 0x18
        iter_obj = e.alloc(0x30, 4)
        iter_vt = e.alloc(0x100, 4)
        e.w32(iter_obj, iter_vt)
        e.w32(res_cont + 0x18, iter_obj)

        # Iterator methods
        def iter_0x4c(em, res_):
            em.ret(eax=0, argbytes=8)

        def iter_0x5c(em, res_):
            # Return an item ID
            em.ret(eax=r.choice([0, r.randrange(1, 100)]), argbytes=8)

        e.hook(iter_vt + 0x4c, iter_0x4c)
        e.hook(iter_vt + 0x5c, iter_0x5c)

        # Resource container vtable
        def res_0x4c(em, res_):
            em.ret(eax=0, argbytes=8)

        def res_0x5c(em, res_):
            em.ret(eax=r.choice([0, r.randrange(1, 100)]), argbytes=8)

        e.hook(res_cont_vt + 0x4c, res_0x4c)
        e.hook(res_cont_vt + 0x5c, res_0x5c)

        em.ret(eax=res_cont, argbytes=8)

    # Tier virtual method at 0x114 (returns resource type)
    def tier_0x114(em, res_):
        em.ret(eax=r.randrange(0x100, 0x200), argbytes=0x10)

    # Container virtual methods
    def container_0x100(em, res_):
        em.ret(eax=r.randrange(0x1000, 0x2000), argbytes=8)

    def container_0x130(em, res_):
        # Two variants are called with different arguments
        em.ret(eax=0, argbytes=0x10)

    def container_0x84(em, res_):
        em.ret(eax=r.randrange(0x3000, 0x4000), argbytes=8)

    # Set up external function stubs
    def ext_4db7c0(em, res_):
        dst = em.arg32(0)
        e.w32(dst, r.getrandbits(32))
        e.w32(dst + 4, r.getrandbits(32))
        e.w32(dst + 8, r.getrandbits(32))
        em.ret(eax=0, argbytes=4)

    # Install hooks
    e.hook(tier_vt + 0x25c, tier_0x25c)
    e.hook(tier_vt + 0x4c, tier_0x4c)
    e.hook(tier_vt + 0x58, tier_0x58)
    e.hook(tier_vt + 0x114, tier_0x114)

    e.hook(container_vt + 0x100, container_0x100)
    e.hook(container_vt + 0x130, container_0x130)
    e.hook(container_vt + 0x84, container_0x84)

    e.hook(0x4db7c0, ext_4db7c0)

    # Create `this` object
    self = e.alloc(0x200, 4)
    self_vt = e.alloc(0x500, 4)
    e.w32(self, self_vt)

    # Self virtual method at 0x2f0 (returns float)
    def self_0x2f0(em, res_):
        import struct
        f = r.uniform(0.5, 2.0)
        fbits = struct.unpack('I', struct.pack('f', f))[0]
        em.ret(eax=fbits, argbytes=4)

    e.hook(self_vt + 0x2f0, self_0x2f0)

    # Fill object with random data
    e.wbytes(self + 0x50, bytes(r.getrandbits(8) for _ in range(0x150)))

    # Set field at 0x8 (pointer to source)
    source = e.alloc(0x20, 4)
    e.w32(self + 8, source)

    # Set field at 0xd6
    e.w32(self + 0xd6, r.randrange(1, 1000))

    return [self]


S(0x513d10, 'GUESS iterate resources', 'thiscall', None, ret=None, gen=_g513d10, note='batch79006')
